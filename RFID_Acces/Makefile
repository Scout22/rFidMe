RFID_logger: RFID_card.o User.o RFID_reader.o main.o mysql_query.o
	g++ -Wall -g -o RFID_logger main.o User.o  mysql_query.o RFID_card.o RFID_reader.o -lnfc -lmysqlcppconn -std=c++11
RFID_card.o: RFID_card.cpp
	g++ -Wall -g -o RFID_card.o -c RFID_card.cpp -lnfc -std=c++11
RFID_reader.o: RFID_reader.cpp
	g++ -Wall -g -o RFID_reader.o -c RFID_reader.cpp -lnfc -std=c++11
main.o: main.cpp
	g++ -Wall -g -o main.o -c main.cpp -lnfc -std=c++11
User.o: User.cpp
	g++ -Wall -g -o User.o -c User.cpp -std=c++11
mysql_query.o: mysql_query.cpp
	g++ -Wall -g -o mysql_query.o -c mysql_query.cpp -lmysqlcppconn
clean: 
	rm *.o RFID_logger
