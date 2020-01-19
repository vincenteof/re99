open Jest;
open Prob02;

describe("Prob02.butLast", () => {
  open Expect;
  test("handles the case of list with two elements", () =>
    expect(butLast([1, 2])) |> toBe(1)
  );
  test("handles the case of list with many element", () =>
    expect((
      butLast([1, 2, 3]),
      butLast([1, 2, 3, 4]),
      butLast([1, 2, 3, 4, 5]),
      butLast([1, 2, 3, 4, 5, 6]),
      butLast(["a", "b", "c", "d", "e"]),
    ))
    |> toEqual((2, 3, 4, 5, "d"))
  );

  testAll(
    "throws exception when the list catains less than two elements",
    [expect(() =>
       butLast([])
     ), expect(() =>
          butLast([1])
        )],
    ret =>
    ret |> toThrow
  );
});

describe("Prob02.butLastSafe", () => {
  open Expect;
  open Belt.Option;
  let getRet = n => n |> butLastSafe |> getExn;
  test("handles the case of list with two elements", () =>
    expect(getRet([1, 2])) |> toBe(1)
  );
  test("handles the case of list with many element", () =>
    expect((
      getRet([1, 2, 3]),
      getRet([1, 2, 3, 4]),
      getRet([1, 2, 3, 4, 5]),
      getRet([1, 2, 3, 4, 5, 6]),
      getRet(["a", "b", "c", "d", "e"]),
    ))
    |> toEqual((2, 3, 4, 5, "d"))
  );
  testAll(
    "returns None when the list catains less than two elements",
    [expect(() =>
       getRet([])
     ), expect(() =>
          getRet([1])
        )],
    ret =>
    ret |> toThrow
  );
});