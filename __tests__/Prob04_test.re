open Jest;
open Prob04;

describe("Prob04.len", () => {
  open Expect;
  test("handles the case of empty list", () =>
    expect(len([])) |> toBe(0)
  );
  test("handles the case of list with element(s)", () =>
    expect([
      len([1]),
      len([1, 2]),
      len([1, 2, 3]),
      len([1, 2, 3, 4]),
      len(["a", "b", "c", "d", "e"]),
    ])
    |> toEqual([1, 2, 3, 4, 5])
  );
});

describe("Prob04.lenUsingFold", () => {
  open Expect;
  test("handles the case of empty list", () =>
    expect(lenUsingFold([])) |> toBe(0)
  );
  test("handles the case of list with element(s)", () =>
    expect([
      lenUsingFold([1]),
      lenUsingFold([1, 2]),
      lenUsingFold([1, 2, 3]),
      lenUsingFold([1, 2, 3, 4]),
      lenUsingFold(["a", "b", "c", "d", "e"]),
    ])
    |> toEqual([1, 2, 3, 4, 5])
  );
});