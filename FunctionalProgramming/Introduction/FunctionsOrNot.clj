(defn read-int []
  (Integer. (read-line)))

(defn function? [lines]
  (->> (group-by first lines)
       (map (fn [[k v]] [k (count v)]))
       (every? (fn [[k v]] (= 1 v)))))

(def T (read-int))

(dotimes [_ T]
    (let [n (read-int)
          lines (repeatedly n (fn [] (->> (clojure.string/split (read-line) #"\s+")
                                          (map #(Integer. %)))))]
      (println (if (function? lines) "YES" "NO"))))
