(defn input []
  (map #(Integer. %) (clojure.string/split (read-line) #"\s+")))

(let [coefficients (input)
      powers (input)
      [low high] (input)
      f (fn [x] (reduce + (map #(* %1 (Math/pow x %2)) coefficients powers)))
      delta 0.001
      intervals (range low (+ high delta) delta)
      area (fn [] (* delta (reduce + 0.0 (map f intervals))))
      volume (fn [] (* delta (reduce + 0.0 (map #(let [r (f %)] (* Math/PI r r)) intervals))))]
  (println (area))
  (println (volume)))

