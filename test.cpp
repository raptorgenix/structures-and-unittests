#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"

#include "Tree.hpp"
#include "Linear.hpp"
#include "HashMap.hpp"


//GLENN HOLZHAUER

//To run this, using "make" should work fine. All test cases are listed here, all print statements will be displayed when running.
//ALl functions are tested in this file for each class


TEST_CASE ( "Tree - Constructor, insert element, search test") {//to verify success of constructor, insert elements into tree and search the tree for them; if this succeed, all three functions are working in the tree
  Tree<int> t1;//int init test
  Tree<std::string> t2; //string init test
    std::string s1 = "abc";
    std::string s2 = "def";
    std::string s3 = "a third string";
    std::string s4 = "final string";

    int n1 = 1;
    int n2 = 3;
    int n3 = 8;
    int n4 = 6;

  t1.insertElement(n1);//inserting ints to tree
  
  t1.insertElement(n2);
  
  t1.insertElement(n3);
  
  t1.insertElement(n4);

  
  t2.insertElement(s1);//inserting strings to tree
  
  t2.insertElement(s2);
  
  t2.insertElement(s3);
  
  t2.insertElement(s4);
  

  REQUIRE(t1.search(2) == false); //search tree to verify success
  REQUIRE(t1.search(3) == true);
  
  REQUIRE(t2.search("ade") == false);
  REQUIRE(t2.search("def") == true);
  

}


TEST_CASE ( "Tree - Delete element test") {
  Tree<int> t3;
  Tree<std::string> t4;
    std::string s1 = "abc";
    std::string s2 = "def";
    std::string s3 = "a third string";
    std::string s4 = "final string";

    int n1 = 1;
    int n2 = 3;
    int n3 = 8;
    int n4 = 6;

  t3.insertElement(n1);
  
  t3.insertElement(n2);
  
  t3.insertElement(n3);
  
  t3.insertElement(n4);

  
  t4.insertElement(s1);
  
  t4.insertElement(s2);
  
  t4.insertElement(s3);
  
  t4.insertElement(s4);
  

  t3.deleteElement(3);
  t3.deleteElement(6);


  t4.deleteElement("abc");




  REQUIRE(t3.search(8) == true);
  REQUIRE(t3.search(3) == false);
  
  REQUIRE(t4.search("abc") == false);
  REQUIRE(t4.search("def") == true);


}


TEST_CASE ( "Tree - Print test") {
  Tree<int> t5;
  Tree<std::string> t6;
    std::string s1 = "abc";
    std::string s2 = "def";
    std::string s3 = "a third string";
    std::string s4 = "final string";

    int n1 = 1;
    int n2 = 3;
    int n3 = 8;
    int n4 = 6;

  t5.insertElement(n1);
  
  t5.insertElement(n2);
  
  t5.insertElement(n3);
  
  t5.insertElement(n4);

  
  t6.insertElement(s1);
  
  t6.insertElement(s2);
  
  t6.insertElement(s3);
  
  t6.insertElement(s4);
  
    std::cout << "Testing Tree print functionality, print is:" << std::endl;

  std::cout << t5 << std::endl;
  std::cout << t6 << std::endl;
  REQUIRE(t5.search(2) == false);
  REQUIRE(t5.search(3) == true);
  
  REQUIRE(t6.search("ade") == false);
  REQUIRE(t6.search("def") == true);


}


TEST_CASE ( "Linear - Constructor, insert, and search test") {
  Linear<int> l1;
  Linear<std::string> l2;
    std::string s1 = "abc";
    std::string s2 = "def";
    std::string s3 = "a third string";
    std::string s4 = "final string";

    int n1 = 1;
    int n2 = 3;
    int n3 = 8;
    int n4 = 6;

  l1.insertElement(n1);
  
  l1.insertElement(n2);
  
  l1.insertElement(n3);
  
  l1.insertElement(n4);

  
  l2.insertElement(s1);
  
  l2.insertElement(s2);
  
  l2.insertElement(s3);
  
  l2.insertElement(s4);
  

  REQUIRE(l1.search(2) == false);
  REQUIRE(l1.search(3) == true);
  
  REQUIRE(l2.search("ade") == false);
  REQUIRE(l2.search("def") == true);


}




TEST_CASE ( "Linear - Delete test") {
  Linear<int> l3;
  Linear<std::string> l4;
    std::string s1 = "abc";
    std::string s2 = "def";
    std::string s3 = "a third string";
    std::string s4 = "final string";

    int n1 = 1;
    int n2 = 3;
    int n3 = 8;
    int n4 = 6;

  l3.insertElement(n1);
  
  l3.insertElement(n2);
  
  l3.insertElement(n3);
  
  l3.insertElement(n4);

  
  l4.insertElement(s1);
  
  l4.insertElement(s2);
  
  l4.insertElement(s3);
  
  l4.insertElement(s4);
  
    l3.deleteElement(8);
    
    l3.deleteElement(1);
    
    l4.deleteElement("a third string");

  REQUIRE(l3.search(1) == false);
  REQUIRE(l3.search(3) == true);
  
  REQUIRE(l4.search("a third string") == false);
  REQUIRE(l4.search("def") == true);


}

TEST_CASE ( "Linear - GetElementAtIndex test") {
  Linear<int> l5;
  Linear<std::string> l6;
    std::string s1 = "abc";
    std::string s2 = "def";
    std::string s3 = "a third string";
    std::string s4 = "final string";

    int n1 = 1;
    int n2 = 3;
    int n3 = 8;
    int n4 = 6;

  l5.insertElement(n1);
  
  l5.insertElement(n2);
  
  l5.insertElement(n3);
  
  l5.insertElement(n4);

  
  l6.insertElement(s1);
  
  l6.insertElement(s2);
  
  l6.insertElement(s3);
  
  l6.insertElement(s4);
  
    
  REQUIRE(l5.getElementAtIndex(0) == 1);
  REQUIRE(l5.getElementAtIndex(2) == 8);
  
  REQUIRE(l6.getElementAtIndex(0) == "abc");
  REQUIRE(l6.getElementAtIndex(1) == "def");


}


TEST_CASE ( "Linear - Print test") {
  Linear<int> l7;
  Linear<std::string> l8;
    std::string s1 = "abc";
    std::string s2 = "def";
    std::string s3 = "a third string";
    std::string s4 = "final string";

    int n1 = 1;
    int n2 = 3;
    int n3 = 8;
    int n4 = 6;

  l7.insertElement(n1);
  
  l7.insertElement(n2);
  
  l7.insertElement(n3);
  
  l7.insertElement(n4);

  
  l8.insertElement(s1);
  
  l8.insertElement(s2);
  
  l8.insertElement(s3);
  
  l8.insertElement(s4);
  
    
    std::cout << "Testing Linear print functionality, print is:" << std::endl;
    
    std::cout << l7 << std::endl;
    std::cout << l8 << std::endl;
    
  REQUIRE(l7.getElementAtIndex(0) == 1);
  REQUIRE(l7.getElementAtIndex(2) == 8);
  
  REQUIRE(l8.getElementAtIndex(0) == "abc");
  REQUIRE(l8.getElementAtIndex(1) == "def");


}



TEST_CASE ( "HashMap - Constructor, hash, insert, and search test") {
  HashMap<int> h1;
  HashMap<std::string> h2;
    std::string s1 = "abc";
    std::string s2 = "def";
    std::string s3 = "a third string";
    std::string s4 = "final string";

    int n1 = 142;
    int n2 = 35;
    int n3 = 8;
    int n4 = 6;

  h1.insertElement(n1);
  
  h1.insertElement(n2);
  
  h1.insertElement(n3);
  
  h1.insertElement(n4);

  
  h2.insertElement(s1);
  
  h2.insertElement(s2);
  
  h2.insertElement(s3);
  
  h2.insertElement(s4);
  
    REQUIRE(h1.search(1) == false);
  REQUIRE(h1.search(3) == false);
     REQUIRE(h1.search(35) == true);
  
  REQUIRE(h2.search("a third string") == true);
  REQUIRE(h2.search("daf") == false);


}




TEST_CASE ( "HashMap - Delete test") {
  HashMap<int> h3;
  HashMap<std::string> h4;
    std::string s1 = "abc";
    std::string s2 = "def";
    std::string s3 = "a third string";
    std::string s4 = "final string";

    int n1 = 142;
    int n2 = 35;
    int n3 = 8;
    int n4 = 6;

  h3.insertElement(n1);
  
  h3.insertElement(n2);
  
  h3.insertElement(n3);
  
  h3.insertElement(n4);

  
  h4.insertElement(s1);
  
  h4.insertElement(s2);
  
  h4.insertElement(s3);
  
  h4.insertElement(s4);
    
    h3.deleteElement(35);
    
    h4.deleteElement("abc");
  
    REQUIRE(h3.search(1) == false);
  REQUIRE(h3.search(8) == true);
     REQUIRE(h3.search(35) == false);
  
  REQUIRE(h4.search("a third string") == true);
  REQUIRE(h4.search("abc") == false);


}



TEST_CASE ( "HashMap - Print test") {
  HashMap<int> h5;
  HashMap<std::string> h6;
    std::string s1 = "abc";
    std::string s2 = "def";
    std::string s3 = "a third string";
    std::string s4 = "final string";

    int n1 = 142;
    int n2 = 35;
    int n3 = 8;
    int n4 = 6;

  h5.insertElement(n1);
  
  h5.insertElement(n2);
  
  h5.insertElement(n3);
  
  h5.insertElement(n4);

  
  h6.insertElement(s1);
  
  h6.insertElement(s2);
  
  h6.insertElement(s3);
  
  h6.insertElement(s4);
    
    std::cout << "Testing HashMap print functionality, print is:" << std::endl;
    
    std::cout<< h5 << std::endl;
    std::cout << h6 << std::endl;
  
    REQUIRE(h5.search(1) == false);
  REQUIRE(h5.search(8) == true);
  
  REQUIRE(h6.search("a third string") == true);
  REQUIRE(h6.search("abe") == false);


}

