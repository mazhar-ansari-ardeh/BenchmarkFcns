import urllib.request
import os


def download_cec2017():
    base_url = "https://raw.githubusercontent.com/FrostNiles/CEC-benchmark-testing-2017-C/master/input_data/"
    os.makedirs("data/cec2017", exist_ok=True)

    # Download shift data
    for i in range(1, 31):
        filename = f"shift_data_{i}.txt"
        url = base_url + filename
        target = f"data/cec2017/shift_{i}.txt"
        if not os.path.exists(target):
            print(f"Downloading {filename}...")
            try:
                urllib.request.urlretrieve(url, target)
            except Exception:
                print(f"Failed to download {filename}")

    # Download rotation matrices for D=10, 30, 50, 100
    for i in range(1, 31):
        for d in [10, 30, 50, 100]:
            filename = f"M_{i}_D{d}.txt"
            url = base_url + filename
            target = f"data/cec2017/M_{i}_D{d}.txt"
            if not os.path.exists(target):
                print(f"Downloading {filename}...")
                try:
                    urllib.request.urlretrieve(url, target)
                except Exception:
                    print(f"Failed to download {filename}")

    # Download shuffle data for Hybrid/Composition
    for i in range(11, 31):
        for d in [10, 30, 50, 100]:
            filename = f"shuffle_data_{i}_D{d}.txt"
            url = base_url + filename
            target = f"data/cec2017/shuffle_{i}_D{d}.txt"
            if not os.path.exists(target):
                print(f"Downloading {filename}...")
                try:
                    urllib.request.urlretrieve(url, target)
                except Exception:
                    # Try without D suffix
                    filename_nod = f"shuffle_data_{i}.txt"
                    url_nod = base_url + filename_nod
                    print(f"Trying {filename_nod}...")
                    try:
                        urllib.request.urlretrieve(url_nod, target)
                    except Exception:
                        print(f"Failed to download shuffle data for F{i} D{d}")


def download_cec2014():
    base_url = "https://raw.githubusercontent.com/7zaa/IEEE-Congress-on-Evolutionary-Computation-Benchmark-functions-suite/main/IEEE-CEC-2014/input_data/"
    os.makedirs("data/cec2014", exist_ok=True)

    # Download shift data
    for i in range(1, 31):
        filename = f"shift_data_{i}.txt"
        url = base_url + filename
        target = f"data/cec2014/shift_{i}.txt"
        if not os.path.exists(target):
            print(f"Downloading {filename}...")
            try:
                urllib.request.urlretrieve(url, target)
            except Exception:
                print(f"Failed to download {filename}")

    # Download rotation matrices for D=10, 30, 50, 100
    for i in range(1, 31):
        for d in [10, 30, 50, 100]:
            filename = f"M_{i}_D{d}.txt"
            url = base_url + filename
            target = f"data/cec2014/M_{i}_D{d}.txt"
            if not os.path.exists(target):
                print(f"Downloading {filename}...")
                try:
                    urllib.request.urlretrieve(url, target)
                except Exception:
                    print(f"Failed to download {filename}")

    # Download shuffle data for Hybrid/Composition
    for i in range(17, 31):  # CEC 2014 Hybrid/Composition starts at F17
        for d in [10, 30, 50, 100]:
            filename = f"shuffle_data_{i}_D{d}.txt"
            url = base_url + filename
            target = f"data/cec2014/shuffle_{i}_D{d}.txt"
            if not os.path.exists(target):
                print(f"Downloading {filename}...")
                try:
                    urllib.request.urlretrieve(url, target)
                except Exception:
                    print(f"Failed to download shuffle data for F{i} D{d}")


def download_cec2019():
    base_url = "https://raw.githubusercontent.com/dmolina/cec2019comp100digit/master/cec2019comp100digit/input_data/"
    os.makedirs("data/cec2019", exist_ok=True)

    # Download shift and rotation data for F1-F10
    for i in range(1, 11):
        # Shift data
        filename = f"shift_data_{i}.txt"
        url = base_url + filename
        target = f"data/cec2019/shift_{i}.txt"
        if not os.path.exists(target):
            print(f"Downloading {filename}...")
            try:
                urllib.request.urlretrieve(url, target)
            except Exception:
                print(f"Failed to download {filename}")

        # Rotation data (only for 10D functions F4-F10 in standard, but dmolina has for all)
        # Actually F1=9, F2=16, F3=18.
        # The repo has M_1_D10, M_2_D10, etc.
        # Let's just download what's there for D=10, D=9, D=16, D=18.
        # Wait, the web_fetch didn't show D=9, D=16, D=18.
        # It showed M_1_D10, M_2_D10...

        for d in [10]:
            filename = f"M_{i}_D{d}.txt"
            url = base_url + filename
            target = f"data/cec2019/M_{i}_D{d}.txt"
            if not os.path.exists(target):
                # print(f"Downloading {filename}...")
                try:
                    urllib.request.urlretrieve(url, target)
                except Exception:
                    pass  # Some might not exist


def download_cec2020():
    base_url = "https://raw.githubusercontent.com/7zaa/IEEE-Congress-on-Evolutionary-Computation-Benchmark-functions-suite/main/IEEE-CEC-2020/input_data/"
    os.makedirs("data/cec2020", exist_ok=True)

    # Internal IDs for CEC 2020 functions F1-F10
    internal_ids = [1, 2, 3, 7, 4, 16, 6, 22, 24, 25]

    # Download shift and rotation data
    for fid in internal_ids:
        # Shift data
        filename = f"shift_data_{fid}.txt"
        url = base_url + filename
        target = f"data/cec2020/shift_{fid}.txt"
        if not os.path.exists(target):
            # print(f"Downloading {filename} for 2020...")
            try:
                urllib.request.urlretrieve(url, target)
            except Exception:
                pass

        # Rotation matrices for D=2, 5, 10, 15, 20
        for d in [2, 5, 10, 15, 20]:
            filename = f"M_{fid}_D{d}.txt"
            url = base_url + filename
            target = f"data/cec2020/M_{fid}_D{d}.txt"
            if not os.path.exists(target):
                try:
                    urllib.request.urlretrieve(url, target)
                except Exception:
                    pass

        # Shuffle data (only for F5=4, F6=16, F7=6)
        if fid in [4, 16, 6]:
            for d in [10, 15, 20]:  # D=2, 5 might not have shuffle
                filename = f"shuffle_data_{fid}_D{d}.txt"
                url = base_url + filename
                target = f"data/cec2020/shuffle_{fid}_D{d}.txt"
                if not os.path.exists(target):
                    try:
                        urllib.request.urlretrieve(url, target)
                    except Exception:
                        pass


def download_cec2022():
    base_url = "https://raw.githubusercontent.com/7zaa/IEEE-Congress-on-Evolutionary-Computation-Benchmark-functions-suite/main/IEEE-CEC-2022/input_data/"
    os.makedirs("data/cec2022", exist_ok=True)

    # Download shift and rotation data for F1-F12
    for fid in range(1, 13):
        # Shift data
        filename = f"shift_data_{fid}.txt"
        url = base_url + filename
        target = f"data/cec2022/shift_{fid}.txt"
        if not os.path.exists(target):
            # print(f"Downloading {filename} for 2022...")
            try:
                urllib.request.urlretrieve(url, target)
            except Exception:
                pass

        # Rotation matrices for D=2, 10, 20
        for d in [2, 10, 20]:
            filename = f"M_{fid}_D{d}.txt"
            url = base_url + filename
            target = f"data/cec2022/M_{fid}_D{d}.txt"
            if not os.path.exists(target):
                try:
                    urllib.request.urlretrieve(url, target)
                except Exception:
                    pass

        # Shuffle data (only for F6-F8)
        if fid in [6, 7, 8]:
            for d in [10, 20]:
                filename = f"shuffle_data_{fid}_D{d}.txt"
                url = base_url + filename
                target = f"data/cec2022/shuffle_{fid}_D{d}.txt"
                if not os.path.exists(target):
                    try:
                        urllib.request.urlretrieve(url, target)
                    except Exception:
                        pass


if __name__ == "__main__":
    download_cec2017()
    download_cec2014()
    download_cec2019()
    download_cec2020()
    download_cec2022()
