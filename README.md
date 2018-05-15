# Große Hausaufgabe für Prog2
Benutzerdokumentation

## Build
Um die Projekt zu bilden, muss man diese Repository klonieren (z.B. von [GitHub](https://github.com/leventeBajczi/prog2-gha/) herunterladen), und eine einzige `make` Befehl ausgeben im Root des Projektes. Diese wird zwei Foldern herstellen, `obj` und `build`, welche jeweils die .o Objektdateien und die hergestellte und laufbare Programm enthalten.

## Laufen lassen
Diese Programm lässt sich mit Hilfe von CLI Switches laufen lassen. Diese sind:
* `-p`: Eine zu füllende Sprachendatei ausschreiben in den folgenden Datei (z.B. `./prog2 -p language.lang` wird eine Sample im File `language.lang` ausschreiben). Falls diese CLI Switch benutzt wird, wird der Programm nach der Filegenerierung sich schließen. 
* `-l`: Eine gefüllte Sprachendatei einladen und verarbeiten. Die Forme dieser Datei ist:
``` json
{
"Move B to A":"mov",
"Add B to A":"add",
"Substract B from A":"sub",
"Swap the upper and lower 4 bits":"swp",
"Shift left, insert 0":"sl0",
"Shift right, insert 0":"sr0",
"Jump to subroutine":"jsr",
"Push value to stack":"push",
"Pop value from stack":"pop"
}
```
* `-f`: Kann nur als die letzte CLI Switch benutzt werden. Wird die nächste Dateien als Subroutine einladen und verarbeiten (können später benutzt werden). Diese Dateien sehen so aus:
```
Name der Subroutine
<instruction>
<instruction>
...
```
Die letzte zwei Switches sind nicht nötig, ohne sie kann die Programm auch laufen gelassen, dann werden die Defaultwerte benutzt.

## Instruktionen
Der VirtualMachine, der benutzt wird, ist eine 8-bit Gerät. 
Wegen Zeitzwang wurde nur einige Instruktionen implementiert (nämlich mov, add, sub, swp, sl0, sr0, jsr, push und pop), aber die Addition von anderen Instruktionen ist sehr einfach (Siehe die Programmiererdokumentation für weitere Informationen).
Diese Instruktionen sind im Defaultsprachendatei:
```
mov A B: kopiert den Wert von B in A
add A B: addiert den Wert von B zu A
sub A B: substrahiert den Wert von B aus A
swp A: Austauscht den untere und obene 4 Bits
sl0 A: Verschiebt den Wert von A nach links mit 1 Bit
sr0 A: Verschiebt den Wert von A nach rechts mit 1 Bit
jsr <label>: Lässt den Instruktionen definiert im Subroutine "label" laufen 
push B: Drückt den Wert von B zum Stack
pop A: Popt den Topwert aus dem Stack im A 
```
Die Werte können sein:
* A: Register (r1-r16), speicher (Im Form (rN) addressiert)
* B: Register (r1-r16), speicher (Im Form (rN) addressiert) oder Literal (0xNN)

Spezielle Instruktionen:
* `quit`: Schließt den Programm
* `(r1)` - `(r16)`: Schreibt den Wert der Speicherbereich addressiert durch einen Register auf dem Bildschirm
* `r1` - `r16`: Schreibt den Wert der Register auf dem Bildschirm

## Ein Beispiel
Die exakte Operation des Programmes zu zeigen steht hier folgender Beispiel für den Benutz des Applikations:
1.  Die Sprachendatei:
    
    Jede Instruktion wird mit einem anderen ersetzt. Die Sprachendatei steht hier:
    ``` json
    {
        "Move B to A":"ertek",
        "Add B to A":"hozzaad",
        "Substract B from A":"kivon",
        "Swap the upper and lower 4 bits":"csere",
        "Shift left, insert 0":"balra",
        "Shift right, insert 0":"jobbra",
        "Jump to subroutine":"ugras",
        "Push value to stack":"mentes",
        "Pop value from stack":"betoltes"
    }
    ```
2. Die Subroutinendatei

    ```
    sbr
    betoltes r1
    hozzaad r1 r1
    kivon r1 0x01
    csere r1
    balra r1
    jobbra r1
    mentes r1
    ```
3. Der Laufsparametern
    
    `./prog2 -l language.lang -f sbr`
4. Die eingetippten Zeilen:
    ```
    ertek r10 0x50
    mentes r10
    r10
    ugras sbr
    betoltes r10
    r10
    ```
5. Die Ausgang:
    ```
    [levente@archlinux test]$ ./prog2 -l language.lang -f sbr
    ertek r10 0x50
    mentes r10
    r10
    Wert von r10: 0x50
    ugras sbr
    betoltes r10
    r10
    Wert von r10: 0x79
    quit
    ```