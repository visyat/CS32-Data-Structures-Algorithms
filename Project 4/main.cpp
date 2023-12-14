//  main.cpp
//  Titanic

#include "Settings.h"
#include "CSVFile.h"
#include "ExampleDataCollector.h"

#include <iostream>
#include <cassert>

#include "Passenger.h"
#include "PassengerDatabase.h"
#include "PassengerOutputTable.h"


int example()
{
    using namespace cs32;
    
    // work with the ExampleDataCollector
    ExampleDataCollector* collector = new ExampleDataCollector();
    CSVFile file( collector );
    file.readFile( PATH_TO_SAMPLE_DATA_G32 );
    
    return( 0 );
}


int sample1( ) {
    
    using namespace std;
    using namespace cs32;

    Passenger passenger;
    passenger.setName( "Jack Dawson" );
    passenger.setEmbarcation( "S" );
    passenger.setClass( "3" );
    passenger.setSurvived( "0" );
    passenger.setFare( "12.50" );
    assert( passenger.getName() == "Jack Dawson" );
    assert( passenger.getClass() == Class::THIRD );
    assert( passenger.getEmbarcation() == Embarcation::SOUTHHAMPTON );
    assert( std::to_string(passenger.getFare()) == "12.500000" );
    assert( passenger.getSurvived() == false );
     
    OutputTableRow row;
    row.setDescription( "testing" );
    row.setSurvived( 5 );
    row.setTotal( 10 );
    assert( row.getDescription() == "testing" );
    assert( row.getSurvived() == 5 );
    assert( row.getTotal() == 10 );
    //cout << "Percentage: " << row.getPercentage() << endl;
    assert( std::to_string(row.getPercentage()) == "0.500000" );

    PassengerDatabase database;
    database.load( PATH_TO_BIGGER_DATA_G32 );
    
    /*database.clearAllPassengers();
    vector< Passenger * > byclass = database.getPassengers();
    cout << "Size of Vector = " << byclass.size() << endl;*/
    
    
    vector< Passenger * > byclass = database.getPassengers_byClass(Class::FIRST, true, -10.00);
    cout << "Size of Vector = " << byclass.size() << endl;
    
    /*
    std::vector< Passenger * >::iterator iter = byclass.begin();
    while (iter != byclass.end())
    {
        cout << (*iter)->getName() << " " << (*iter)->getFare() << " " << (*iter)->getSurvived() << " ";
        if ((*iter)->getClass() == Class::FIRST)
            cout << "First Class";
        cout << endl;
        iter++;
        
    }*/
    
    
    if (database.loaded())
    {
        vector< Passenger * > byclass = database.getPassengers_byClass(Class::FIRST, true, -10.00);
        vector< Passenger * > byembark = database.getPassengers_byEmbarcation(Embarcation::SOUTHHAMPTON, true, 0.00);
        
        Passenger * p = database.getPassenger_byName( "Howard" );
        if (p)
            p->setEmbarcation( "S" );
       
 
        PassengerOutputTable t( byclass );
        t.setDescription( "List of First Class Survivors With Fare > 0" );
        t.setOutputField( Field::BYCLASS );
        assert( t.getDescription() == "List of First Class Survivors With Fare > 0" );
        assert( t.getOutputField() == Field::BYCLASS );
        t.display();
        
        cout << "\n";
        
        vector< Passenger * > byclassdied = database.getPassengers_byClass(Class::FIRST, false, -10.00);
        PassengerOutputTable t1( byclassdied );
        t1.setDescription( "List of First Class Died With Fare > 0" );
        t1.setOutputField( Field::BYCLASS );
        t1.display();

        cout << "\n";
        
        vector< Passenger * > all = database.getPassengers();
        PassengerOutputTable t2( all );
        t2.setDescription( "List of all passengers by class" );
        t2.setOutputField( Field::BYCLASS );
        t2.display();
        
        cout << "\n";
     
        assert( t2.rowCount() == 4 );
        // first class
        row = t2.getRow( 0 );
        //assert( row.getSurvived() == 4 );
        //assert( row.getTotal() == 5 );
        //assert( std::to_string(row.getPercentage()) == "0.800000" );
        
        t2.setDescription( "List of all passengers by embarcation" );
        t2.setOutputField( Field::BYEMBARCATION );
        t2.display();
        
        cout << "\n";
        
        t2.setDescription( "List of all passengers by fare" );
        t2.setOutputField( Field::BYFARE );
        t2.display();
        
        cout << "\n";
        
        t2.setDescription( "What is shown by NOVALUE??" );
        t2.setOutputField( Field::NOVALUE );
        t2.display();
        
        cout << "\n";
        
    }
    else
    {
        cout << "database was not loaded correctly" << endl;
        cout << PATH_TO_MOVIE_DATA_G32 << " is not working!" << endl;
    }
     
    
    cout << "All tests passed!" << endl;
    return( 0 );
}

int sample2()
{
    using namespace std;
    using namespace cs32;
    
    // this set of test cases checks to see if a passenger is created, if the default values are set properly, and if the rest of the operations work correctly
    
    Passenger passenger;
    assert ( passenger.getName() == "");
    passenger.setName( "Rithwik Narendra" );
    assert ( passenger.getName() != "");
    assert ( passenger.getFare() == 0);
    assert ( passenger.getClass() == Class::NOTKNOWN);
    passenger.setEmbarcation( "C" );
    passenger.setClass( "5" );
    passenger.setSurvived( "1" );
    passenger.setFare( "12.82" );
    assert( passenger.getName() != "Jack Dawson" );
    assert( passenger.getClass() == Class::NOTKNOWN );
    assert( passenger.getEmbarcation() == Embarcation::CHERBOURG );
    assert( std::to_string(passenger.getFare()) == "12.820000" );
    assert( passenger.getSurvived() == true );
        
    Passenger passenger2;
    passenger2.setName( "Dean Phillips" );
    passenger2.setClass("2");
    passenger2.setSurvived( "0" );
    passenger2.setEmbarcation( "P" );
    assert( passenger2.getName() == "Dean Phillips" );
    assert( passenger2.getClass() == Class::SECOND );
    assert( passenger2.getEmbarcation() == Embarcation::NOTKNOWN );
    assert( passenger2.getSurvived() != true );
        
        
    // Next, I will test load and isLoaded by loading the movie data
    
    PassengerDatabase database;
    if (database.loaded())
    {
        cout << "No";
    }
    database.load (PATH_TO_MOVIE_DATA_G32);
    if (database.loaded())
    {
     
        // Now that loaded and isLoaded has been checked, I will create Passenger vectors to determine if database's operations are working
        vector< Passenger * > byclass = database.getPassengers_byClass(Class::FIRST, true, -10.00);

        vector< Passenger * > byembark = database.getPassengers_byEmbarcation(Embarcation::SOUTHHAMPTON, true, 0.00);
        
        assert(byembark.size() == 5);
        assert(byclass.size() == 4);
        
        
        // Here, I check getPassenger_byName to determine if it works when the name is present and absent
        
        Passenger * p1 = database.getPassenger_byName("J. Bruce Ismay");
        
        if (p1)
        {
            assert(p1->getClass() == Class::SECOND);
            assert(p1->getClass() != Class::FIRST);
            assert(p1->getEmbarcation() == Embarcation::SOUTHHAMPTON);
            assert(p1->getFare() == 35);
            cout << "tests pasts for J. Bruce Ismay" << endl;
        }
        
        Passenger * p2 = database.getPassenger_byName("J.Bruce Ismay");
        if (p2 == nullptr)
        {
            cout << "not found" << endl; // should return not found
        }
        else
        {
            cout << "incorrect" << endl;
        }
 
        //now, I will check passengeroutput table
        
        vector< Passenger * > total = database.getPassengers();
        PassengerOutputTable t2( total );
        t2.setDescription( "List of all passengers by fare" );
        t2.setOutputField( Field::BYFARE );
     
        
        // Now I will check outputtablerow by going through every row
        t2.display();
        assert( t2.rowCount() == 5 );
        // $ 10 - $ 25
        OutputTableRow row = t2.getRow( 2 );
        assert ( row.getDescription() == "$10-$25");
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 5 );
        assert( row.getPercentage() == 0 );
        
        OutputTableRow row0 = t2.getRow( 0 );
        // not known
        assert ( row0.getDescription() == "Not Known");
        assert( row0.getSurvived() == 0 );
        assert( row0.getTotal() == 0 );
        assert( row0.getPercentage() == 0 );
        
        OutputTableRow row1 = t2.getRow( 1 );
        assert ( row1.getDescription() == "$1-$10");
        assert( row1.getSurvived() == 0 );
        assert( row1.getTotal() == 0 );
        assert( row1.getPercentage() == 0 );
        
        OutputTableRow rowBig = t2.getRow( 4 );
        assert ( rowBig.getDescription() == ">$50");
        assert( rowBig.getSurvived() == 4 );
        assert( rowBig.getTotal() == 5 );
        assert( rowBig.getPercentage() == 0.800000 );
        
        // Now, I will check examples for the remaining fields
        
        
        PassengerOutputTable t( byclass );
        t.setDescription( "List of First Class Survivors With Fare > 0" );
        t.setOutputField( Field::BYFARE ); // There should only be results in the last row
        assert( t.getDescription() == "List of First Class Survivors With Fare > 0" );
        assert( t.getOutputField() == Field::BYFARE );
        t.display();
        assert ( t.rowCount() == 5);
        // This set of asserts checks if there are results elsewhere
        assert(t.getRow(0).getTotal() == 0);
        assert(t.getRow(1).getTotal() == 0);
        assert(t.getRow(2).getTotal() == 0);
        assert(t.getRow(3).getTotal() == 0);
        //Now to check the row where there are first class passengers only
        assert(t.getRow(4).getTotal()!= 0);
        
        
        // Now to check died
        vector< Passenger * > byclassdied = database.getPassengers_byClass(Class::SECOND, false, -10.00);
        PassengerOutputTable t1( byclassdied );
        t1.setDescription( "List of Second Class Died With Fare > 0" );
        t1.setOutputField( Field::BYCLASS );
        t1.display();
        assert(t1.getRow(3).getTotal() == 0);
        assert(t1.getOutputField() == Field::BYCLASS);
        assert(t1.getRow(1).getSurvived() == 0);
        assert(t1.getRow(1).getTotal() != 0);
        
        // now to test embarcation
        
        PassengerOutputTable em( byembark );
        em.setDescription( "List of Surviving Passengers by Embarcation" );
        em.setOutputField( Field::BYEMBARCATION );
        em.display();
        int i = 0;
        assert(em.getOutputField() == Field::BYEMBARCATION);
        // this while loop ensures that the only embarcation location with information is southampton
        while (i < em.rowCount())
        {
            if (em.getRow(i).getDescription() != "Southhampton")
            {
                assert(em.getRow(i).getTotal() == 0);
                i++;
            }
            else
            {
                assert(em.getRow(i).getPercentage() == 1);
                i++;
            }
        }
        cout << "Movie asserts passed" << endl;
    }
    // a more comprehensive set of asserts on a bigger dataset
    
    PassengerDatabase database2;
    database2.load (  PATH_TO_BIGGER_DATA_G32);
    
    // checkloaded
    if (database2.loaded())
    {
        //To do a more comprehensive set of asserts, I want all passenger data; I do not want to subset by any filters. This will allow me to ensure that all of the operations work from a bird's eye view. Then, I will do smaller/piecemeal asserts on filters.
        vector< Passenger * > big = database2.getPassengers();
        
        // I will now check for each filter
        
        //First, I will comprehensively test the operations and methods for byClass
        
        PassengerOutputTable classCheck( big );
        classCheck.setDescription( "List of all passengers by class" );
        classCheck.setOutputField( Field::BYCLASS );
        classCheck.display();
        assert( classCheck.rowCount() == 4 );
        assert( classCheck.getOutputField() == Field::BYCLASS );
        assert( classCheck.getDescription() != "Ugh so many asserts" );
        
        // We are given that there are no passengers for whom we do not know the class
        
        OutputTableRow rownkC = classCheck.getRow(3);
        assert( rownkC.getTotal() == 0);
        
        // asserts based on the spec
        
        assert( classCheck.getRow(0).getTotal() == 323);
        assert( classCheck.getRow(1).getTotal() == 277);
        assert( classCheck.getRow(2).getTotal() == 709);
        
        assert( classCheck.getRow(0).getSurvived() + classCheck.getRow(1).getSurvived() + classCheck.getRow(2).getSurvived() + classCheck.getRow(3).getSurvived() == 500);
        
        
        // Now, I will comprehensively test the operations and methods for byEmbarcation
        
        
        PassengerOutputTable emCheck( big );
        emCheck.setDescription( "List of all passengers by embarcation");
        emCheck.setOutputField( Field::BYEMBARCATION );
        emCheck.display();

        assert( emCheck.rowCount() == 4 );
        assert( emCheck.getOutputField() == Field::BYEMBARCATION );
        assert( emCheck.getDescription() == "List of all passengers by embarcation" );
        
        // asserts based on the spec
        
        assert( emCheck.getRow(0).getTotal() == 270);
        assert( emCheck.getRow(1).getTotal() == 123);
        assert( emCheck.getRow(2).getTotal() == 914);
        assert( emCheck.getRow(3).getTotal() == 2);
        
        // assert which checks getTotal, getSurvived, getRow, and also makes sure that the total # of deaths is accurate
        
        assert( emCheck.getRow(0).getTotal() + emCheck.getRow(1).getTotal() + emCheck.getRow(2).getTotal() + emCheck.getRow(3).getTotal() - (emCheck.getRow(0).getSurvived() + emCheck.getRow(1).getSurvived() + emCheck.getRow(2).getSurvived() + emCheck.getRow(3).getSurvived()) == 809);
        
        // // Now, I will comprehensively test the operations and methods for byFare
        
        PassengerOutputTable fare( big );
        fare.setDescription( "List of all passengers by fare");
        fare.setOutputField( Field::BYFARE );
        fare.display();

        assert( fare.rowCount() == 5 );
        assert( fare.getOutputField() == Field::BYFARE );
        assert( fare.getDescription() != "List of all  passengers by fare" );

        // asserts based on the spec

        assert( fare.getRow(0).getTotal() == 18);
        assert( fare.getRow(1).getTotal() == 474);
        assert( fare.getRow(2).getTotal() == 330);
        assert( fare.getRow(3).getTotal() == 247);
        assert( fare.getRow(4).getTotal() == 240);
        
        // Now, I will check filtration
        
        vector< Passenger * > bigclasslived = database2.getPassengers_byClass(Class::SECOND, true, 500.000);
        PassengerOutputTable tren( bigclasslived );
        tren.setDescription( "List of Second Class Survivors With Fare > 500" );
        tren.setOutputField( Field::BYFARE );
        tren.display();
        
        // basic asserts
        assert ( tren.rowCount() == 5);
        assert (tren.getOutputField() != Field::NOVALUE);
        
        // the vector should be empty
        assert(bigclasslived.size() < 1);
        assert ( tren.getRow(3).getSurvived() == 0);

        // an actually useful check of filtration
        vector< Passenger * > usefulclasslived = database2.getPassengers_byClass(Class::SECOND, true, 14.000);
        PassengerOutputTable tren2( usefulclasslived );
        tren2.setDescription( "List of Second Class Survivors With Fare > 14" );
        tren2.setOutputField( Field::BYFARE );
        tren2.display();
        
        // basic asserts
        assert ( tren2.rowCount() == 5);
        assert (tren2.getOutputField() != Field::BYEMBARCATION);
        assert(usefulclasslived.size() > 1);
        assert ( tren2.getRow(3).getSurvived() != 0);
    }
    
    cout << "All tests 1 passed!" << endl;
    return( 0 );
}

int sample3()
{
    using namespace std;
    using namespace cs32;
    
    PassengerDatabase database;
    
    database.load( PATH_TO_BIGGER_DATA_G32 );
    if (database.loaded())
    {
        vector < Passenger *> entireDataset = database.getPassengers();
        PassengerOutputTable t( entireDataset );
        t.setDescription( "List of Entire Titanic Dataset By Class" );
        t.setOutputField( Field::BYCLASS );
        assert( t.getDescription() == "List of Entire Titanic Dataset By Class" );
        assert( t.getOutputField() == Field::BYCLASS );
        t.display();
        
        assert( t.rowCount() == 4 );
        OutputTableRow row = t.getRow( 0 );
        assert( row.getSurvived() == 200 );
        assert( row.getTotal() == 323 );
        assert( std::to_string(row.getPercentage()) == "0.619195" );
        row = t.getRow( 1 );
        assert( row.getSurvived() == 119 );
        assert( row.getTotal() == 277 );
        assert( std::to_string(row.getPercentage()) == "0.429603" );
        row = t.getRow( 2 );
        assert( row.getSurvived() == 181 );
        assert( row.getTotal() == 709 );
        assert( std::to_string(row.getPercentage()) == "0.255289" );
        row = t.getRow( 3 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        
        t.setDescription( "List of Entire Titanic Dataset By Embarcation" );
        t.setOutputField( Field::BYEMBARCATION );
        assert( t.getDescription() == "List of Entire Titanic Dataset By Embarcation" );
        assert( t.getOutputField() == Field::BYEMBARCATION );
        t.display();
        
        assert( t.rowCount() == 4 );
        row = t.getRow( 0 );
        assert( row.getSurvived() == 150 );
        assert( row.getTotal() == 270 );
        assert( std::to_string(row.getPercentage()) == "0.555556" );
        row = t.getRow( 1 );
        assert( row.getSurvived() == 44 );
        assert( row.getTotal() == 123 );
        assert( std::to_string(row.getPercentage()) == "0.357724" );
        row = t.getRow( 2 );
        assert( row.getSurvived() == 304 );
        assert( row.getTotal() == 914 );
        assert( std::to_string(row.getPercentage()) == "0.332604" );
        row = t.getRow( 3 );
        assert( row.getSurvived() == 2 );
        assert( row.getTotal() == 2 );
        assert( std::to_string(row.getPercentage()) == "1.000000" );
        
        t.setDescription( "List of Entire Titanic Dataset By Fare" );
        t.setOutputField( Field::BYFARE );
        assert( t.getDescription() == "List of Entire Titanic Dataset By Fare" );
        assert( t.getOutputField() == Field::BYFARE );
        t.display();
        
        assert( t.rowCount() == 5 );
        row = t.getRow( 0 );
        assert( row.getSurvived() == 2 );
        assert( row.getTotal() == 18 );
        assert( std::to_string(row.getPercentage()) == "0.111111" );
        row = t.getRow( 1 );
        assert( row.getSurvived() == 108 );
        assert( row.getTotal() == 474 );
        assert( std::to_string(row.getPercentage()) == "0.227848" );
        row = t.getRow( 2 );
        assert( row.getSurvived() == 128 );
        assert( row.getTotal() == 330 );
        assert( std::to_string(row.getPercentage()) == "0.387879" );
        row = t.getRow( 3 );
        assert( row.getSurvived() == 104 );
        assert( row.getTotal() == 247 );
        assert( std::to_string(row.getPercentage()) == "0.421053" );
        row = t.getRow( 4 );
        assert( row.getSurvived() == 158 );
        assert( row.getTotal() == 240 );
        assert( std::to_string(row.getPercentage()) == "0.658333" );
        
        vector < Passenger *> onlyFirstClass = database.getPassengers_byClass(Class::FIRST, true, 25);
        PassengerOutputTable onlyFirst (onlyFirstClass);
        onlyFirst.setDescription( "List of First Class Survivors With Fare > 25" );
        onlyFirst.setOutputField( Field::BYCLASS );
        assert( onlyFirst.getDescription() == "List of First Class Survivors With Fare > 25" );
        assert( onlyFirst.getOutputField() == Field::BYCLASS );
        onlyFirst.display();
        
        assert( onlyFirst.rowCount() == 4 );
        row = onlyFirst.getRow( 0 );
        assert( row.getSurvived() == 199 );
        assert( row.getTotal() == 199 );
        assert( std::to_string(row.getPercentage()) == "1.000000" );
        row = onlyFirst.getRow( 1 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        row = onlyFirst.getRow( 2 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        row = onlyFirst.getRow( 3 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        
        vector < Passenger *> onlyFirstClassDead = database.getPassengers_byClass(Class::FIRST, false, 25);
        PassengerOutputTable onlyFirstDead (onlyFirstClassDead);
        onlyFirstDead.setDescription( "List of First Class Dead With Fare > 25" );
        onlyFirstDead.setOutputField( Field::BYCLASS );
        assert( onlyFirstDead.getDescription() == "List of First Class Dead With Fare > 25" );
        assert( onlyFirstDead.getOutputField() == Field::BYCLASS );
        onlyFirstDead.display();
        
        assert( onlyFirstDead.rowCount() == 4 );
        row = onlyFirstDead.getRow( 0 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 116 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        row = onlyFirstDead.getRow( 1 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        row = onlyFirstDead.getRow( 2 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        row = onlyFirstDead.getRow( 3 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        
        vector < Passenger *> onlySecondClassSur = database.getPassengers_byClass(Class::SECOND, true, 25);
        PassengerOutputTable onlySecond (onlySecondClassSur);
        onlySecond.setDescription( "List of Second Class Survivors With Fare > 25" );
        onlySecond.setOutputField( Field::BYCLASS );
        assert( onlySecond.getDescription() == "List of Second Class Survivors With Fare > 25" );
        assert( onlySecond.getOutputField() == Field::BYCLASS );
        onlySecond.display();
        
        assert( onlySecond.rowCount() == 4 );
        row = onlySecond.getRow( 0 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        row = onlySecond.getRow( 1 );
        assert( row.getSurvived() == 54 );
        assert( row.getTotal() == 54 );
        assert( std::to_string(row.getPercentage()) == "1.000000" );
        row = onlySecond.getRow( 2 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        row = onlySecond.getRow( 3 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        
        vector < Passenger *> onlySecondClassDead = database.getPassengers_byClass(Class::SECOND, false, 25);
        PassengerOutputTable onlySecondDead (onlySecondClassDead);
        onlySecondDead.setDescription( "List of Second Class Dead With Fare > 25" );
        onlySecondDead.setOutputField( Field::BYCLASS );
        assert( onlySecondDead.getDescription() == "List of Second Class Dead With Fare > 25" );
        assert( onlySecondDead.getOutputField() == Field::BYCLASS );
        onlySecondDead.display();
        
        assert( onlySecondDead.rowCount() == 4 );
        row = onlySecondDead.getRow( 0 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        row = onlySecondDead.getRow( 1 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 48 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        row = onlySecondDead.getRow( 2 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        row = onlySecondDead.getRow( 3 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        
        
        vector < Passenger *> onlyCherSur = database.getPassengers_byEmbarcation(Embarcation::CHERBOURG, true, 25);
        PassengerOutputTable onlyCherSurvived (onlyCherSur);
        onlyCherSurvived.setDescription( "List of Cher Survivors With Fare > 25" );
        onlyCherSurvived.setOutputField( Field::BYEMBARCATION );
        assert( onlyCherSurvived.getDescription() == "List of Cher Survivors With Fare > 25" );
        assert( onlyCherSurvived.getOutputField() == Field::BYEMBARCATION );
        onlyCherSurvived.display();
        
        assert( onlyCherSurvived.rowCount() == 4 );
        row = onlyCherSurvived.getRow( 0 );
        assert( row.getSurvived() == 104 );
        assert( row.getTotal() == 104 );
        assert( std::to_string(row.getPercentage()) == "1.000000" );
        row = onlyCherSurvived.getRow( 1 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        row = onlyCherSurvived.getRow( 2 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        row = onlyCherSurvived.getRow( 3 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        
        vector < Passenger *> onlyCherDie = database.getPassengers_byEmbarcation(Embarcation::CHERBOURG, false, 25);
        PassengerOutputTable onlyCherDied (onlyCherDie);
        onlyCherDied.setDescription( "List of Cher Survivors With Fare > 25" );
        onlyCherDied.setOutputField( Field::BYEMBARCATION );
        assert( onlyCherDied.getDescription() == "List of Cher Survivors With Fare > 25" );
        assert( onlyCherDied.getOutputField() == Field::BYEMBARCATION );
        onlyCherDied.display();
        
        assert( onlyCherDied.rowCount() == 4 );
        row = onlyCherDied.getRow( 0 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 48 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        row = onlyCherDied.getRow( 1 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        row = onlyCherDied.getRow( 2 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        row = onlyCherDied.getRow( 3 );
        assert( row.getSurvived() == 0 );
        assert( row.getTotal() == 0 );
        assert( std::to_string(row.getPercentage()) == "0.000000" );
        
        
    }
    else
    {
        cout << "database was not loaded correctly" << endl;
        cout << PATH_TO_BIGGER_DATA_G32 << " is not working!" << endl;
    }

    cout << "All tests 2 passed!" << endl;
    return (0);
}

int main()
{
    //example();
    sample1();
    sample2();
    sample3();
    
    return( 0 );
}
