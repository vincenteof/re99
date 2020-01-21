open Jest;
open Prob10;

describe("Prob09.compress", () => {
  open Expect;
  test("handles the case of empty list", () =>
    expect(lenEncode([])) |> toEqual([])
  );
  test("handles the case of list with many elements", () =>
    expect((
      lenEncode(["a"]),
      lenEncode(["a", "a"]),
      lenEncode(["a", "a", "a"]),
      lenEncode(["a", "b", "b", "a", "a", "b", "b"]),
      lenEncode([
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
         [(1, "a")],
         [(2, "a")],
         [(3, "a")],
         [(1, "a"), (2, "b"), (2, "a"), (2, "b")],
         [(4, "a"), (1, "b"), (2, "c"), (2, "a"), (1, "d"), (4, "e")],
       ))
  );
});