
void process_filelist_fork(char** fnames, int num)
{
 int i, p1, p2, p3, i1, i2, i3, pp, p;
 g_file_info = (fileinfo*)malloc(sizeof(fileinfo) * num);
 if (!g_file_info) panic(HERE, "malloc fileinfo");
 p1 = fork();
 p2 = fork();
 p3 = fork();
 i1 = !!p1;
 i2 = !!p2;
 i3 = !!p3;
 pp = (i1<<2) + (i2<<1) + i3;
 p = (pp == 7);
 printf("fork: (%d,%d,%d) -> (%d,%d,%d) -> (%d,%d)\n", p1, p2, p3, i1, i2, i3, pp, p);
 for (i=0;i<num;i++) 
	{
	  if (p && (i%8) != pp)
	  {
	      // printf("Parent %d skips: %d\n", pp, i);
	      continue;
	  }
	  else if (!p && (i%8) != pp)
	  {
	      // printf("Child %d skips: %d\n", pp, i);
	      continue;
	  }

	  init_fileinfo(&g_file_info[i]);
	  g_file_info[i].fname = (char*)malloc((sizeof(char) * strlen(fnames[i])) + 1);
	  strcpy(g_file_info[i].fname, fnames[i]);
	  g_file_info[i].i = i;
	  free((void*)fnames[i]);
	  fnames[i] = NULL;
	  if (!process_file(&g_file_info[i], num))
		{
			printf("Failed processing: %s\n", g_file_info[i].fname);
		}
	}
 printf("Zapis konfiguracji bazy w pliku %s\n", g_dbout_file);
 if (p) 
 {	/* parent wait for child to finish */
     printf("Parent waits for children\n");
     for (i=0;i<8;i++) {
       printf("Parent waits for child %d\n", i+1);
       wait(NULL);
     }
     printf("Parent waited OK\n");
 }
 else
 {   /* children finishes */  
     printf("Child finishes\n");
     exit(0);
 }
 save_dbfile(num);
}
