open Jest;
open Prob05;

describe("Prob05.reverse", () => {
  open Expect;
  test("handles the case of empty list", () =>
    expect(reverse([])) |> toEqual([])
  );
  test("handles the case of list with element(s)", () =>
    expect((
      reverse([1]),
      reverse([1, 2]),
      reverse([1, 2, 3]),
      reverse([1, 2, 3, 4]),
      reverse(["a", "b", "c", "d", "e"]),
    ))
    |> toEqual((
         [1],
         [2, 1],
         [3, 2, 1],
         [4, 3, 2, 1],
         ["e", "d", "c", "b", "a"],
       ))
  );
});