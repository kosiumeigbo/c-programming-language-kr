#include <stdio.h>

main() {
  int fahr;

  for (fahr = 300; fahr >= 0; fahr = fahr - 20) {
    printf("%3d\t%6.1f\n", fahr, ((5.0 / 9.0) * (fahr - 32.0)));
  }

  //   float fahr, celsius;
  //   float lower, upper, step;
  //   char *fahrTableHeading, *celsiusTableHeading;
  //   lower = 0;   /* lower limit of temperature scale */
  //   upper = 300; /* upper limit */
  //   step = 20;   /* step size */

  //   fahrTableHeading = "Fahrenheit";
  //   celsiusTableHeading = "Celsius";

  //   /* print Fahrenheit-Celsius table for fahr = 0, 20, ..., 300 */
  //   fahr = lower;
  //   printf("%s\t%s\n", fahrTableHeading, celsiusTableHeading);
  //   while (fahr <= upper) {
  //     celsius = (5.0 / 9.0) * (fahr - 32.0);
  //     printf("%10.0f\t%7.1f\n", fahr, celsius);
  //     fahr = fahr + step;
  //   }
  //   printf("\n");

  //   /* print Celsius-Fahrenheit table for celsius = 0, 20, ..., 300 */
  //   celsius = lower;
  //   printf("%s\t%s\n", celsiusTableHeading, fahrTableHeading);
  //   while (celsius <= upper) {
  //     fahr = ((9.0 * celsius) / 5.0) + 32.0;
  //     printf("%7.0f\t%10.1f\n", celsius, fahr);
  //     celsius = celsius + step;
  //   }
}