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
# flow: create db -> create user -> use db -> grant access only to the DB -> exit -> login with new user -> check dbs
# follow the above flow everytime while creating a new user!
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

## Tables

```bash
# Create table
create table students(ID INT PRIMARY KEY, NAME VARCHAR(50), AGE INT, NOTES VARCHAR(100));
show tables;
DROP TABLE tablename;

INSERT INTO students values (1, "Haseeb", 24, "MSCS Student"); # single record
INSERT INTO students values (2, "Ayesha", 22, "Job"), (3, "Ateeq", 25, "Job"); # multiple record
```

## SQL DDL Clauses
- works on the structure of db
Deals with the structure and schema of a database.
Used to define, modify, or delete database objects such as tables, indexes, and schemas.
Clauses: CREATE, ALTER, DROP, TRUNCATE, RENAME, COMMENT, USE

```bash
CREATE TABLE Employees ( EmployeeID INT PRIMARY KEY, FirstName VARCHAR(50), LastName VARCHAR(50); # CREATE
ALTER TABLE Employees ADD COLUMN Email VARCHAR(100); # ALTER
DROP TABLE Employees; # DROP
TRUNCATE TABLE Employees; # TRUNCATE
);
```

## SQL DML CLAUSES
- works on data of db
Focuses on the manipulation and management of data within database tables.
Used to retrieve, insert, update, or delete data.

```bash
SELECT * FROM Employees; # SELECT
INSERT INTO Employees (EmployeeID, FirstName, LastName) VALUES (1, 'Alice', 'Smith'); # INSERT
UPDATE Employees SET LastName = 'Johnson' WHERE EmployeeID = 1; # UPDATE
DELETE FROM Employees WHERE EmployeeID = 1; # DELETE
```

## Queries

Cheatsheet: https://learnsql.com/blog/sql-basics-cheat-sheet/sql-basics-cheat-sheet-letter.pdf

auto_increment


