#include <stdio.h>
int MAX_ITEMS = 255;

void print_pad(int size) {
  for (int i = 0; i <= 16 - size; i++) {
    printf(" ");
  }
  printf(" |\n");
}

void print_array(int arr[], int size) {
  for (int x = size - 1; x >= 0; x--) {
    int element = arr[x];
    if (element < 10) {
      printf("%d", arr[x]);
      continue;
    }
    printf("%c", arr[x]);
  }
}

int to_bin(int decimal, int result[]) {
  int idx = 0;
  if (!decimal) {
    result[0] = 0;
    return idx + 1;
  }
  while (decimal) {
    result[idx] = decimal & 1;
    decimal = decimal >> 1;
    idx++;
  }
  return idx;
}

int to_oct(int decimal, int result[]) {
  int idx = 0;
  if (!decimal) {
    result[0] = 0;
    return idx + 1;
  }
  while (decimal) {
    result[idx] = decimal & 7;
    decimal = decimal >> 3;
    idx++;
  }
  return idx;
}

int to_hex(int decimal, int result[]) {
  int idx = 0;
  if (!decimal) {
    result[0] = 0;
    return idx + 1;
  }
  while (decimal) {
    int remainder = decimal & 15;
    result[idx] = remainder >= 10 ? (remainder - 10) + 65 : remainder;
    decimal = decimal >> 4;
    idx++;
  }
  return idx;
}

int main() {
  int dec;
  printf("Input decimal number: ");
  // WARN: this will treat any non digit input as zero
  scanf("%d", &dec);
  if (dec < 0) {
    printf("The number must be positive\n");
    return main();
  }
  printf("***** Result *****\n");
  // INFO: Octal conversion
  printf("| %-12s | ", "Octal");
  int oct[MAX_ITEMS];
  int oct_len = to_oct(dec, oct);
  print_array(oct, oct_len);
  print_pad(oct_len);

  // INFO: Hexadecimal conversion
  printf("| %-12s | ", "Hexadecimal");
  int hex[MAX_ITEMS];
  int hex_len = to_hex(dec, hex);
  print_array(hex, hex_len);
  print_pad(hex_len);

  // INFO: Binary conversion
  printf("| %-12s | ", "Binary");
  int bin[MAX_ITEMS];
  int bin_len = to_bin(dec, bin);
  print_array(bin, bin_len);
  print_pad(bin_len);
  return 0;
}
