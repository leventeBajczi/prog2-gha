# Konzolbasiertes Interpreter eines dynamisch geschriebenen, konfigurierbaren Spraches

## Die Idee

Die Hauptidee des Programmes ist, den User zu erlauben eine eigene Beschreibungssprache zu konstruieren und dasselbe Sprache in einem dynamisch geschriebenen Art im Programm verwenden um eine eigene Programm zusammenzustellen (der später im File gespeichert werden kann). 
Das Sprache ist an den Prinzipen des Assembly-Spraches basiert, und enthält nur sehr atomische Instruktionen, die natürlich jede sinnvolle Problem lösen lassen.

## Die geplannte Umsetzung

Der Benutzer bekommt eine CLI Tool, die die folgende machen kann:

1. Eine leere, zu füllende Sprachendatei erstellen (JSON-basiert, damit es automatisch generiert werden kann sowohl aus dieser Programm als auch mit Hilfe von 3rd Party Programms).
2. Eine gefüllte Sprachendatei einladen (und natürlich verifizieren, ob es wirklich gut gefüllt wurde).
3. Aus der eingeladeten Sprache einen inneren Konzol erstellen, in denen der Benutzer kann folgendes tun:
    1. Schritt für Schritt eine Programm eintippen.
    2. Subroutine und Labels definieren (mit Hilfe von einer reservierten Schlusswort oder Bezeichnung, z.B. `def` oder `:`).
    3. Definitionsbibliotheken aus speziellen Dateien einladen.
    4. Soweit eingetippte Schritte ansehen und die ganze History im Datei speichern.
    5. Registern, Stack und Speicher im File (oder der Standardausgang) schreiben
4. Mit Hilfe von verschiedenen Sprachendateien Programme zwischen Sprachen umwandeln (erledigt z.B. wirkliche Assemblykode zu generieren, der später assembliert werden kann).

## Der Komplexität

Obwohl ich nach eine sehr einfaches Implementation streben möchte, damit es nicht schwierig wird den ganzen Software überzusehen, ist es unvermeidlich einige komplexere Sachen im Program verwenden. Damit zu hilfen habe ich die folgende Typusgraphen erstellt: 

![VirtualMachine](typus_vm.png)

![Speicher und geerbte Klassen](typus_speicher.png)

![Dateientypen](typus_dateien.png)

![JSON Hilfsklasse](typus_json.png)

Diese sind natürlich nur Planen, und können während der Entwicklung geändert werden. 

Die folgende Komplexitätskriterien sind im Plan (aus der 5 spezifizierte Kriterien):
* Templates
* Operatorüberladung
* Mehrfachvererbung
* Dynamische Membervariable