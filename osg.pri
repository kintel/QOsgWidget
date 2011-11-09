osg {
  message("Configuring osg: $$OSG")
  CONFIG += link_pkgconfig
  PKGCONFIG += openscenegraph-osg

  contains(OSG, Qt): PKGCONFIG += openscenegraph-osgQt
}
