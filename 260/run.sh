#g++ test_case.cpp
#./a.out > in.txt
g++ main.cpp
./a.out < in.txt > M.txt
g++ D.cpp
./a.out < in.txt > B.txt
diff M.txt B.txt
