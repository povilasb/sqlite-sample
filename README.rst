=====
About
=====

This is basic sample demonstrating how to embed sqlite3 to c++ program.


Dependencies
============

* sqlite3 development files::

        $ sudo apt-get install libsqlite3-dev

* sqlite3 CLI tool (**optional**)::

        $ sudo apt-get install sqlite3


Usin Sqlite3 CLI
================


Create databse
---------------

::

        $ sqlite3 test.db
        sqlite> .exit


Create table
------------

::

        $ sqlite3 test.db
        sqlite> create table users(id text primary key, pass text);
        sqlite> .exit


Insert new records to table
---------------------------

::

        $ sqlite3 test.db
        sqlite> insert into users values ('user1', 'pass1');
        sqlite> .exit


Select records from table
-------------------------

::

        $ sqlite test.db
        sqlite> select * from users;
        sqlite> .exit
