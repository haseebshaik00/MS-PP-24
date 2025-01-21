# SQL Commands

## Setup

```bash
brew install mysql
brew services start mysql
mysql_secure_installation # set your password
mysql -u root -p # login with password - haseeb123; use root as haseeb
```

## Users

```bash
SELECT User, Host FROM mysql.user; # show all users along with their host

CREATE USER 'someuser'@'localhost' IDENTIFIED BY 'somepassword'; # create user - haseeb(user), host(localhost) and haseeb123(password)

# Grant All Priveleges On All Databases; * . * as myTestDB.*
# create db first and then grant user access to the db; don't do *.*
# flow: create db -> create user -> use db -> grant access only to the DB
GRANT ALL PRIVILEGES ON * . * TO 'someuser'@'localhost';
FLUSH PRIVILEGES;

SHOW GRANTS FOR 'someuser'@'localhost'; # Show Grants

REVOKE ALL PRIVILEGES, GRANT OPTION FROM 'someuser'@'localhost'; # Remove Grants

DROP USER 'someuser'@'localhost'; # Delete User

exit; # Exit
```

## Databases

```bash
SHOW DATABASES;
CREATE DATABASE dbName;
DROP DATABASE dbName;
USE acme;
```
