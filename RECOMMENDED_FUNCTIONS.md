# Recommended Future Benchmark Functions

This list contains 200 high-value benchmark functions categorized by their type and impact on the library's utility.

## 1. Classic Single-Objective Functions (100)
These functions represent the "missing links" from the foundational literature (e.g., Jamil & Yang survey) and are prioritized for implementation to make the library the most comprehensive "classic" collection.

1. Aluffi-Pentini [SAME AS ZIRILLI]
2. Baluja [DONE]
3. Box-Betts Quadratic Sum [DONE]
4. Colville [DONE]
5. Cross-Leg-in-Tray [DONE]
6. Damavandi [DONE]
7. Dolan [DONE]
8. Engvall [DONE]
9. Fletcher-Powell [DONE]
10. Freudenstein-Roth [DONE]
11. Hansen [DONE]
12. Helical Valley [DONE]
13. Jennrich-Sampson [DONE]
14. Judge [DONE]
15. Kowalik [DONE]
16. Kulnevich [DONE]
17. Meyer [DONE]
18. Miele-Cantrell [DONE]
19. Mishra N. 1 to N. 8 [DONE]
27. Mishra N. 9 to N. 12 [DONE]
31. Multi-Modal [DONE]
32. Needle Eye [DONE]
33. Parsopoulos [DONE]
34. Pathological [DONE]
35. Paviani [DONE]
36. Pen Holder [DONE]
37. Pinter [DONE]
38. Price N. 1 [DONE], Price N. 2 to N. 4 [DONE]
42. Quintic [DONE]
43. Rotated Hyper-Ellipsoid [DONE]
44. Sargan [DONE]
45. Schwefel N. 2.25 [DONE]
46. Schwefel N. 2.26 [DONE]
47. Sine Envelope Sine Wave [DONE]
48. Step N. 1 to N. 3 [DONE]
51. Table [DONE]
52. Test Tube Holder [DONE]
53. Trefethen [DONE]
54. Trigonometric N. 1 to N. 2 [DONE]
56. Ursem N. 1, N. 3, N. 4 [DONE]
59. Ursem Waves [DONE]
60. Venter Sobiezcczanski-Sobieski [DONE]
61. Wayburn-Seader N. 1, N. 3 [DONE]
63. Ackley N. 5 to N. 6 [DONE]
66. Alpine N. 3 to N. 5 [DONE]
69. Bohachevsky N. 4 to N. 5 [DONE]
71. Bukin N. 1, N. 3, N. 5 [DONE]
76. Chichinadze N. 2 [DONE]
77. De Jong N. 6 [DONE], N. 7, N. 8
80. Dixon-Price N. 2 to N. 3 [DONE]
82. Egg Holder N. 2 [DONE]
83. Giunta N. 2 [DONE]
84. Griewank N. 2 to N. 3 [DONE]
86. Hartmann N. 4 [DONE], N. 5
88. Himmelblau N. 2 [DONE]
89. Hosaki N. 2 [DONE]
90. Keane N. 2 [DONE]
91. Langermann N. 2 [DONE]
92. Leon N. 2 [DONE]
93. Levy N. 1 to N. 3 [DONE]
96. Matyas N. 2 [DONE]
97. McCormick N. 2 [DONE]
98. Michalewicz N. 2, N. 5, N. 10 [DONE]

## 2. Multi-Objective Functions (50) [DONE]
Prioritizing the WFG suite and missing unconstrained/constrained sets.

### Walking Fish Group (WFG) Suite [DONE]
- **WFG1 - WFG9**: Scalable problems with diverse Pareto geometries. [DONE]

### Missing Classic MO Functions [DONE]
- **OKA1, OKA2**: Non-linear Pareto sets. [DONE]
- **Veldhuizen Suite (MOP1-7)**: Classic bi-objective problems. [DONE]
- **Kita**: Non-convex Pareto front. [DONE]
- **Deb**: Disconnected Pareto front. [DONE]

### CEC 2009 Unconstrained (UF) Suite [DONE]
- **UF1 - UF10**: Complex non-linear correlations. [DONE]

### CEC 2009 Constrained (CF) Suite [DONE]
- **CF1 - CF10**: Non-linear constraints in MO. [DONE]

### Many-Objective (MaF) Suite [DONE]
- **MaF1 - MaF10**: Problems scalable to 10+ objectives. [DONE]

## 3. Multi-Fidelity Functions (50) [DONE]
Focused on physical surrogates and systematic bi-fidelity adaptations.

### Classic Physical Surrogates [DONE]
- **Borehole MF** [DONE]
- **Branin MF (Toal adjustable version)** [DONE]
- **Currin MF** [DONE]
- **Friedman MF** [DONE]
- **Gano MF** [DONE]
- **Mainini MF (Heterogeneous)** [DONE]
- **OTL Circuit MF** [DONE]
- **Park MF (91a, 91b)** [DONE]
- **Piston MF** [DONE]
- **Robot Arm MF** [DONE]
- **Wing Weight MF** [DONE]
- **Xiong 1D MF** [DONE]

### Bi-Fidelity Library Adaptations [DONE]
- Systematic LF versions for all 35+ core benchmark functions. [DONE]
  - Ackley, Rastrigin, Griewank, Schwefel, Sphere, Easom, Eggholder, Goldstein-Price, Himmelblau, Six-Hump Camelback, Bohachevsky, Matyas, Booth, Zakharov, Dixon-Price, Levy, Michalewicz, Styblinski-Tank, Bent Cigar, Discus, Elliptic, Katsuura, Shubert, Step, Trid, Alpine, Beale, Bird, Adjiman, Bartels-Conn, Brown, Bukin, Cross-in-Tray, HappyCat. [DONE]

## 4. Future Work: Competition Suites
These suites involve complex rotation and shift logic that requires dedicated data files.
- **CEC 2014 Suite (30 functions)**
- **CEC 2017 Suite (30 functions)**
- **CEC 2019 100-Digit Challenge (10 functions)**
- **CEC 2022 Suite (12 functions)**
