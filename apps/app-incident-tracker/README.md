# Incident Tracker App

## Overview

The Incident Tracker App is a simple console application written in C++. It employs object-oriented programming (OOP) principles to allow users to register and track various types of incidents, such as Television, Internet, and Phone issues. Each incident is associated with a priority, duration, severity, name, and description.

## Features

- Register new incidents with details such as type, description, priority, duration, and severity.
- View a list of registered incidents, including details like incident number, type, description, priority, duration, severity, and total cost.
- Export the list of incidents to XML format (feature to be implemented).

## Total Service Cost Calculation

The total service cost is calculated based on the following table:

| Service      | Cost (₡) | Priority 1 and 2 (₡) | Priority 3, 4, and 5 (₡) | Duration 1-12 (₡) | Duration 13-24 (₡) | Duration 25-48 (₡) | Severity High (%) | Severity Medium (%) | Severity Low (%) |
|--------------|----------|-----------------------|-------------------------|-------------------|--------------------|-------------------|---------------------|----------------------|-------------------|
| Television   | 1000     | 150                   | 100                     | 120               | 140                | 160               | 8                 | 6                   | 4                 |
| Internet     | 1500     | 200                   | 150                     | 130               | 135                | 140               | 8.5               | 9                   | 9.5               |
| Phone     | 750      | 90                    | 80                      | 100               | 110                | 125               | 3.5               | 4.5                 | 5.5               |

## Prerequisites

- C++ compiler
- Standard Template Library (STL)
- C++11 or later

## How to Use

1. Compile the code using a C++ compiler.
2. Run the compiled executable to launch the Incident Tracker App.
3. Follow the on-screen prompts to register incidents or view the incidents list.

## Author
Jurgen Alfaro

## Example Output

Main menu:

```c++
++++++++ INCIDENT TRACKER APP - v0.2.0 ++++++++

Enter an option:
[i]ncidents list
[r]egister incident
[q]uit

choice:
```

Register incident menu: 

```c++
++++++++ REGISTER INCIDENT ++++++++

Enter incident type:
[t]elevision
[i]nternet
[p]hone
[b]ack to previous menu

choice: t
Enter incident description: No service in El Roble
Enter incident priority (1 to 5): 1
Enter incident duration (min: 1 hour| max: 48 hours): 6
Enter incident severity ([h]igh, [m]edium, [l]ow): h

Incident added to the list!

[r]egister new incident
[b]ack to main menu
choice:
```

Incidents menu:

```c++
++++++++ INCIDENTS LIST ++++++++

Incident #:     1
Type:           Television
Description:    No service in El Roble
Priority:       1
Duration:       6
Severity:       HIGH
Total cost:     $1371.60
++++++++++++++++++++++++++++++++
Incident #:     2
Type:           Internet
Description:    Slow internet speed
Priority:       3
Duration:       2
Severity:       MEDIUM
Total cost:     $1940.20
++++++++++++++++++++++++++++++++
[b]ack to main menu
[e]xport XML
choice:
```

**Note**: The app shows the dolar ($) symbol instead of the colones (₡). This will be fixed in a future release.
