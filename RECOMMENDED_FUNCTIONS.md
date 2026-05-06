# Recommended Future Benchmark Functions

This list contains 200 high-value benchmark functions categorized by their type and impact on the library's utility.

## 1. Classic Single-Objective Functions (100)
These functions represent the "missing links" from the foundational literature (e.g., Jamil & Yang survey) and are prioritized for implementation to make the library the most comprehensive "classic" collection.

1. Aluffi-Pentini
2. Baluja
3. Box-Betts Quadratic Sum
4. Colville
5. Cross-Leg-in-Tray
6. Damavandi
7. Dolan
8. Engvall
9. Fletcher-Powell
10. Freudenstein-Roth
11. Hansen
12. Helical Valley
13. Jennrich-Sampson
14. Judge
15. Kowalik
16. Kulnevich
17. Meyer
18. Miele-Cantrell
19. Mishra N. 1 to N. 12 (12 functions)
31. Multi-Modal
32. Needle Eye
33. Parsopoulos
34. Pathological
35. Paviani
36. Pen Holder
37. Pinter
38. Price N. 1 to N. 4 (4 functions)
42. Quintic
43. Rotated Hyper-Ellipsoid
44. Sargan
45. Schwefel N. 2.25
46. Schwefel N. 2.26
47. Sine Envelope Sine Wave
48. Step N. 1 to N. 3 (3 functions)
51. Table
52. Test Tube Holder
53. Trefethen
54. Trigonometric N. 1 to N. 2 (2 functions)
56. Ursem N. 1, N. 3, N. 4 (3 functions)
59. Ursem Waves
60. Venter Sobiezcczanski-Sobieski
61. Wayburn-Seader N. 1, N. 3 (2 functions)
63. Ackley N. 5 to N. 7 (3 functions)
66. Alpine N. 3 to N. 5 (3 functions)
69. Bohachevsky N. 4 to N. 5 (2 functions)
71. Bukin N. 1, N. 3, N. 5, N. 7, N. 8 (5 functions)
76. Chichinadze N. 2
77. De Jong N. 6 to N. 8 (3 functions)
80. Dixon-Price N. 2 to N. 3 (2 functions)
82. Egg Holder N. 2
83. Giunta N. 2
84. Griewank N. 2 to N. 3 (2 functions)
86. Hartmann N. 4 to N. 5 (2 functions)
88. Himmelblau N. 2
89. Hosaki N. 2
90. Keane N. 2
91. Langermann N. 2
92. Leon N. 2
93. Levy N. 1 to N. 3 (3 functions)
96. Matyas N. 2
97. McCormick N. 2
98. Michalewicz N. 2, N. 5, N. 10 (3 functions)

## 2. Multi-Objective Functions (50)
Prioritizing the WFG suite and missing unconstrained/constrained sets.

### Walking Fish Group (WFG) Suite (9)
- **WFG1 - WFG9**: Scalable problems with diverse Pareto geometries.

### Missing Classic MO Functions (11)
- **OKA1, OKA2**: Non-linear Pareto sets.
- **Veldhuizen Suite (MOP1-7)**: Classic bi-objective problems.
- **Kita**: Non-convex Pareto front.
- **Deb**: Disconnected Pareto front.

### CEC 2009 Unconstrained (UF) Suite (10)
- **UF1 - UF10**: Complex non-linear correlations.

### CEC 2009 Constrained (CF) Suite (10)
- **CF1 - CF10**: Non-linear constraints in MO.

### Many-Objective (MaF) Suite (10)
- **MaF1 - MaF10**: Problems scalable to 10+ objectives.

## 3. Multi-Fidelity Functions (50)
Focused on physical surrogates and systematic bi-fidelity adaptations.

### Classic Physical Surrogates (15)
- **Branin MF (Toal adjustable version)**
- **Currin MF**
- **Park MF**
- **Borehole MF**
- **Wing Weight MF**
- **OTL Circuit MF**
- **Piston MF**
- **Robot Arm MF**
- **Friedman MF**
- **Gratias MF**
- **Xiong MF**
- **Gano MF**
- **Mainini MF**
- **Gratias-H / L**

### Bi-Fidelity Library Adaptations (35)
Systematic LF versions for the most "famous" functions in the current library.
- **Ackley MF**
- **Rastrigin MF**
- **Griewank MF**
- **Schwefel MF**
- **Sphere MF**
- **Easom MF**
- **Eggholder MF**
- **Goldstein-Price MF**
- **Himmelblau MF**
- **Six-Hump Camelback MF**
- **Bohachevsky MF**
- **Matyas MF**
- **Booth MF**
- **Zakharov MF**
- **Dixon-Price MF**
- **Levy MF**
- **Michalewicz MF**
- **Styblinski-Tank MF**
- **Bent Cigar MF**
- **Discus MF**
- **Elliptic MF**
- **Katsuura MF**
- **Shubert MF**
- **Step MF**
- **Trid MF**
- **Alpine MF**
- **Beale MF**
- **Bird MF**
- **Adjiman MF**
- **Bartels-Conn MF**
- **Branin MF**
- **Brown MF**
- **Bukin MF**
- **Cross-in-Tray MF**
- **HappyCat MF**

## 4. Future Work: Competition Suites
These suites involve complex rotation and shift logic that requires dedicated data files.
- **CEC 2014 Suite (30 functions)**
- **CEC 2017 Suite (30 functions)**
- **CEC 2019 100-Digit Challenge (10 functions)**
- **CEC 2022 Suite (12 functions)**
