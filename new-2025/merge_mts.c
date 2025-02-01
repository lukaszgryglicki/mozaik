#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _item {
  int x, y, idx, r, g, b;
} item;

int by_idx(const void *p1, const void *p2) {
  return ((item*)p1)->idx > ((item*)p2)->idx;
}

int main(int lb, char** par) {
  int i, j, k, nproc, snap_x, snap_y, snap_x1, snap_y1, x, y, r, g, b, idx, n;
  char *ofn, *ifn, *snapdir, *snapdir1;
  FILE *db, *idb;
  item *items;
  item it;

  if (lb < 2) {
    printf("%s: you need to specify DB name prefix, for example: abc will generate abc.dat from abc.dat.? files\n", par[0]);
    return 1;
  }

  ofn = (char*)malloc( (strlen(par[1]) + 4) * sizeof(char));
  sprintf(ofn, "%s.dat", par[1]);
  db = fopen(ofn, "w");
  if (!db) {
    printf("cannot write DB: %s\n", ofn);
	  return 2;
  }

  ifn = (char*)malloc( (strlen(par[1]) + 6) * sizeof(char));
  snapdir = (char*)malloc(0x100*sizeof(char));
  snapdir1 = (char*)malloc(0x100*sizeof(char));
  strcpy(snapdir1, "");
  snap_x1 = snap_y1 = n = -1;
  items = NULL;
  k = 0;

  for (i=0;i<0x10;i++) {
    sprintf(ifn, "%s.dat.%x", par[1], i);
    idb = fopen(ifn, "r");
    if (!idb) {
      printf("cannot read db: %s\n", ifn);
	    return 3;
    }
    fscanf(idb, "SNAPDIR=%s\n", snapdir);
    if (!strcmp(snapdir1, "")) strcpy(snapdir1, snapdir);
    else if (strcmp(snapdir1, snapdir)) {
      printf("(%x) different snap dirs: '%s' <> '%s'\n", i, snapdir1, snapdir);
      fclose(idb);
      return 4;
    }
    fscanf(idb, "PROCESSED=%d\n", &nproc);
    if (n < 0) {
      n = (nproc + 1) * 0x10;
      items = (item*)malloc(n * sizeof(item));
    }
    fscanf(idb, "SNAP=%d,%d\n", &snap_x, &snap_y);
    if (snap_x1 < 0 && snap_y1 < 0) {
      snap_x1 = snap_x;
      snap_y1 = snap_y;
    } else if (snap_x1 != snap_x || snap_y1 != snap_y) {
      printf("(%x) different snap sizes: (%d x %d) <> (%d x %d)\n", i, snap_x1, snap_y1, snap_x, snap_y);
      fclose(idb);
      return 5;
    }
    for (j=0;j<nproc;j++)
    {
      fscanf(idb, "SIZE=%d,%d SNAP=%d,%d,%d COLOR=%d,%d,%d\n", &x, &y, &snap_x, &snap_y, &idx, &b, &g, &r);
      if (snap_x1 != snap_x || snap_y1 != snap_y) {
        printf("(%x, %d, %d) different snap sizes: (%d x %d) <> (%d x %d)\n", i, j, idx, snap_x1, snap_y1, snap_x, snap_y);
        fclose(idb);
        return 6;
      }
      it.x = x;
      it.y = y;
      it.idx = idx;
      it.r = r;
      it.g = g;
      it.b = b;
      memcpy((void*)&(items[k]), (void*)&it, sizeof(item));
      k ++;
    }
  }
  qsort((void*)items, k, sizeof(item), by_idx);
  /* printf("all items: %d\n", k); */
  fprintf(db, "SNAPDIR=%s\n", snapdir1);
  fprintf(db, "PROCESSED=%d\n", k);
  fprintf(db, "SNAP=%d,%d\n", snap_x1, snap_y1);
  for (i=0;i<k;i++)
  {
	  fprintf(db, "SIZE=%d,%d SNAP=%d,%d,%d COLOR=%d,%d,%d\n", items[i].x, items[i].y, snap_x1, snap_y1, items[i].idx, items[i].b, items[i].g, items[i].r);
  }
  fclose(db);
	return 0;
}
