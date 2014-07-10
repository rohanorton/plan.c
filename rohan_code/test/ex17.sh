#!/bin/bash -e
APP=./bin/ex17
DB=db.dat
red='\e[0;31m'
green='\e[032m'
nocolor='\e[0m'
SUCCESS="${green} TEST PASSES ${nocolor}"
FAILURE="${red} TEST FAILS! ${nocolor}"

function should() {
    if [ "$1" == "succeed" ]; then
        $2
        EXIT_CODE=$?
        echo "Error Code: $EXIT_CODE"
        if [ "$EXIT_CODE" == "0" ]; then
            echo -e $SUCCESS;
        else
            echo -e $FAILURE;
        fi
    elif [ "$1" == "fail" ]; then
        $2
        EXIT_CODE=$?
        echo "Error Code: $EXIT_CODE"
        if [ "$EXIT_CODE" = "0" ]; then
            echo -e $FAILURE;
        else
            echo -e $SUCCESS;
        fi
    else
        echo "What should it do???";
    fi;

    echo 
}


echo "Ex17 Tests:";
echo "===========";
echo
## ensure db is deleted
rm $DB

echo "Running without params should error:"
should fail "$APP"

echo "Create database should produce new file:"
$APP $DB c 512 100
should succeed "find $DB"

echo "Set address should add to database:"
$APP $DB s 1 rohan rohan.orton@gmail.com
should succeed "$APP $DB g 1"

echo "Setting without an address should fail:"
should fail "$APP $DB s 2 ellie" 

echo "Deleting an address that exits should work:"
should succeed "$APP $DB d 1" 
    
echo "Deleting a non-existent address should fail:"
should fail "$APP $DB d 9" 


## And lets set up the db for a little bit of tinkering later
$APP $DB s 1 Rohan rohan.orton@gmail.com
$APP $DB s 2 Billig susannahbillig@gmail.com
$APP $DB s 3 Ellie e.julings@gmail.com
$APP $DB s 4 Abe abe@abesmith.co.uk

echo "Should be able to find data in the database searching for name:"
should succeed "$APP $DB f Rohan"

echo "Should be able to find data in the database searching for address:"
should succeed "$APP $DB f gmail"
