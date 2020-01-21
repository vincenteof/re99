open Jest;
open Prob08;

describe("Prob08.compress", () => {
  open Expect;
  test("handles the case of empty list", () =>
    expect(compress([])) |> toEqual([])
  );
  test("handles the case of list with many elements", () =>
    expect((
      compress(["a"]),
      compress(["a", "a"]),
      compress(["a", "a", "a"]),
      compress(["a", "b", "b", "a", "a", "b", "b"]),
      compress([
        "a",
        "a",
        "a",
        "a",
        "b",
        "c",
        "c",
        "a",
        "a",
        "d",
        "e",
        "e",
        "e",
        "e",
      ]),
    ))
    |> toEqual((
         ["a"],
         ["a"],
         ["a"],
         ["a", "b", "a", "b"],
         ["a", "b", "c", "a", "d", "e"],
       ))
  );
});

describe("Prob08.compressSimple", () => {
  open Expect;
  test("handles the case of empty list", () =>
    expect(compressSimple([])) |> toEqual([])
  );
  test("handles the case of list with many elements", () =>
    expect((
      compressSimple(["a"]),
      compressSimple(["a", "a"]),
      compressSimple(["a", "a", "a"]),
      compressSimple(["a", "b", "b", "a", "a", "b", "b"]),
      compressSimple([
        "a",
        "a",
        "a",
        "a",
        "b",
        "c",
        "c",
        "a",
        "a",
        "d",
        "e",
        "e",
        "e",
        "e",
      ]),
    ))
    |> toEqual((
         ["a"],
         ["a"],
         ["a"],
         ["a", "b", "a", "b"],
         ["a", "b", "c", "a", "d", "e"],
       ))
  );
});