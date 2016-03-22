size_t size = SIZE;
size_t blocksize = BLOCKSIZE;

i=1;
char* arg;
while(i<argc) {
   arg=argv[i];
   if (!strncmp(arg,"--size",6)) size = atoi(argv[++i]);
   else if (!strncmp(arg,"--blocksize",11)) blocksize = atoi(argv[++i]);
   else {
      fprintnf(stderr,"unrecognized option.\n");
      exit(-1);
   }
}

