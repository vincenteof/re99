open Jest;
open Prob01;

describe("Prob01.last1", () => {
  open Expect;
  test("handles the case of list with one element", () =>
    expect(last1([1])) |> toBe(1)
  );
  test("handles the case of list with many element", () =>
    expect((
      last1([1, 2]),
      last1([1, 2, 3]),
      last1([1, 2, 3, 4]),
      last1([1, 2, 3, 4, 5]),
      last1(["a", "b", "c", "d"]),
    ))
    |> toEqual((2, 3, 4, 5, "d"))
  );
});

describe("Prob01.last2", () => {
  open Expect;
  test("handles the case of list with one element", () =>
    expect(last2([1])) |> toBe(1)
  );
  test("handles the case of list with many element", () =>
    expect((
      last2([1, 2]),
      last2([1, 2, 3]),
      last2([1, 2, 3, 4]),
      last2([1, 2, 3, 4, 5]),
      last2(["a", "b", "c", "d"]),
    ))
    |> toEqual((2, 3, 4, 5, "d"))
  );
});