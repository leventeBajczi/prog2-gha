# Konzolbasiertes Interpreter eines dynamisch geschriebenen, konfigurierbaren Spraches

## Die Idee

Die Hauptidee des Programmes ist, den User zu erlauben eine eigene Beschreibungssprache zu konstruieren und dasselbe Sprache in einem dynamisch geschriebenen Art im Programm verwenden um eine eigene Programm zusammenzustellen (der später im File gespeichert werden kann). 
Das Sprache ist an den Prinzipen des Assembly-Spraches basiert, und enthält nur sehr atomische Instruktionen, die natürlich jede sinnvolle Problem lösen lassen.

## Die geplannte Umsetzung

Der Benutzer bekommt eine CLI Tool, die die folgende machen kann:

1. Eine leere, zu füllende Sprachendatei erstellen (JSON-basiert, damit es automatisch generiert werden kann sowohl aus meiner Programm als auch mit Hilfe von 3rd Party Programms).
2. Eine gefüllte Sprachendatei einladen (und natürlich verifizieren, ob es wirklich gut gefüllt wurde).
3. Aus der eingeladeten Sprache einen inneren Konzol erstellen, in denen der Benutzer kann folgendes tun:
    1. Schritt für Schritt eine Programm eintippen.
    2. Subroutine und Labels definieren (mit Hilfe von einer reservierten Schlusswort, z.B. `subr` und `label).
    3. 