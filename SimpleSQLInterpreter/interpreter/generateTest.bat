antlr sqlLexer.g4 sqlParser.g4 -o test -Dlanguage=Java
cd test
javac sql*.java
grun sql root -gui