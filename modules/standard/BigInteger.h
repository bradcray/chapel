static void print_mpz_loc(mpz_t x) {
  printf("%p\n", x->_mp_d);
}
