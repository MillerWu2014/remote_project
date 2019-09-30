import numpy as np
import utm

def generate_grid_coords(bbox, width=500):
    """
    parameters
    ----------
        bbox:list,as [(minlon,minlat),(maxlon, maxlat)]
        width:int, the width of cell,default 500m
    return
    ------
         list,grid coords like[(lon,lat),...,(lon,lat)]
    """

    def _fun(a, b, i):
        if a > b:
            return list(np.arange(a, b, -i))
        else:
            return list(np.arange(a, b, i))

    p1, p2 = bbox
    p1_lon, p1_lat = p1
    p2_lon, p2_lat = p2

    p1_x, p1_y, z1, b1 = utm.from_latlon(p1_lat, p1_lon)
    p2_x, p2_y, z2, b2 = utm.from_latlon(p2_lat, p2_lon, z1)

    # 栅格化
    lats = _fun(p1_x, p2_x, width)
    lons = _fun(p1_y, p2_y, width)

    glat, glon = np.meshgrid(lats, lons)
    grid_coors = np.vstack([glat.ravel(), glon.ravel()]).T
    print("glat shape:", glat.shape)
    # 转换成lat-lon
    grid_latlon = [utm.to_latlon(x, y, z1, b1, strict=False) for x, y in grid_coors]

    return [(lon, lat) for lat, lon in grid_latlon]


if __name__ == "__main__":
    coord_range = [(101.55740957, 26.31218077), (103.17899112, 28.85231643)]
    xy = generate_grid_coords(coord_range)
    print(len(xy))
