:: Tests/at_simple_error_ok.txt                    OK
:: Tests/test_file_copn_ok.txt                     OK
:: Tests/test_file_csq_not_ok_1.txt                NOK
:: Tests/test_file_csq_not_ok_2.txt                NOK
:: Tests/test_file_csq_not_ok_3.txt                NOK
:: Tests/test_file_csq_not_ok_4_no_cr_present.txt  NOK
:: Tests/test_file_csq_ok.txt                      OK
:: Tests/test_file_simple_at_ok.txt                OK


gcc -c *.c
gcc -o program *.o
del *.o
::program.exe Tests/at_simple_error_ok.txt
::program.exe Tests/test_file_simple_at_ok.txt
::program.exe Tests/test_file_csq_ok.txt
::program.exe Tests/test_file_copn_ok.txt
::program.exe Tests/test_file_csq_not_ok_1.txt
::program.exe Tests/test_file_csq_not_ok_2.txt
::program.exe Tests/test_file_csq_not_ok_3.txt
::program.exe Tests/test_file_csq_not_ok_4_no_cr_present.txt
::program.exe