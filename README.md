## Partial DNA Digestion Mapping

This program solves the partial DNA digestion mapping problem.

Input data are the results of an experiment using a single restriction enzyme that cuts copies of a studied DNA fragment at its restriction sites, but after different digestion times. In the theoretical model, digestion times are chosen so that the fragment is cut in exactly one site, then two sites, and so on, until all restriction sites are cut.

As a result, we obtain a multiset `A` containing all pairwise distances between restriction sites (including fragment ends), supplemented by the length of the entire DNA fragment.

The goal is to reconstruct the arrangement of restriction sites in the DNA fragment such that the distances between all pairs of restriction sites exactly match the multiset `A`.
Example

Input:

A = {2,3,3,4,6,6,7,8,9,9,11,12,15,15,18}

Output:

Map = (3,4,2,6,3)

>[!NOTE]
>Currently, the input file is hardcoded, however it will be made possible for user to chose the desired file.

## Usage

```bash
c++ 'AKwB 4.cpp' -o ./a.out
./a.out
```
