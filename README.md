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


The relationship between the number of restriction cuts `k` and the number of elements in the multiset `A` can be described by the formula:

```math
|A| = \binom{k+2}{2}
```
<br/><br/>
Assuming there are no errors in the input data, the computational complexity of this problem remains an open question.

### Data

Instances are labeled using the following format:

`[instance_id]-[k]a-[asc/desc]`

where:

- **`instance_id`** – identifier of the dataset variant (different test cases generated from different input sets),
- **`k`** – number of places of digestion, 
- **`a`** – generation variant identifier (fixed type of input generator used for all instances in this set),
- **`asc / desc`** – ordering of the input multiset:
  - **`asc`** – values sorted in ascending order,
  - **`desc`** – values sorted in descending order.

This naming scheme allows systematic comparison of algorithm performance across different problem sizes and input orderings while keeping the underlying instance structure consistent.

## Usage

To build and run the program, simply type:
```bash
make
```
