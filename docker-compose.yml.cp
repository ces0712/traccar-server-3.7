version: '2'
services: 

 mysql:
  image: mysql:5.6
  #restart: always
  hostname: mysql
  environment:
   - "MYSQL_ROOT_PASSWORD=yourpasswordhere"
  volumes:
   - mysql:/var/lib/mysql/
   - ./conf/mysql.sql:/docker-entrypoint-initdb.d/mysql.sql
  ports:
   - "33061:3306"
 traccar:
  image: traccar/traccar:3.17
  hostname: traccar
  #restart: always
  ports:
   - "5000-5150:5000-5150"
   - "5000-5150:5000-5150/udp"
   - "8082:8082"
  volumes:
   - traccar-db:/opt/traccar/data/database
   - ./conf/traccar.xml:/opt/traccar/conf/traccar.xml:ro
   - /etc/timezone:/etc/timezone:ro 
   - /etc/localtime:/etc/localtime:ro
   - ./conf/logs:/opt/traccar/logs:rw

volumes:
 traccar-db:
 mysql:
