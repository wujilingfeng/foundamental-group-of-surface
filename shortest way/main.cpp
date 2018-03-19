#include "shortest.h"


int main()
{
	igl::viewer::Viewer viewer;
	PMyMesh mesh;
	Mos mos(mesh, viewer);
	igl::readOFF("e:/off/eight.off", mos.V, mos.F);
	OpenMesh::IO::Options opt;
	if (!OpenMesh::IO::read_mesh(mesh, "e:/off/eight.off", opt))
	{
		for (int i=0;i<30;i++)
		{
			printf_s("¶ÁÈ¡Ê§°Ü\r\n");
		}
		
		return -1;
	}
	//init_edge_length();
	VertexHandle v = mesh.vertex_handle(0), v1=mesh.vertex_handle(80);
	mos.init_edge_length();
	mos.set_destination(v);
	mos.find_shortestway(v1);
	mos.drawedge();
	mos.draw_scene();

	
	//mos.init_edge_length();
	//mos.set_destination(v);
	/*list<int> mylist;
	mylist.push_back(1);*/
	
	//viewer.data.set_colors(c);
	
	//mos.draw_scene();
	/*viewer.callback_init = [&](igl::viewer::Viewer &viewer)
	{viewer.ngui->addVariable("kk", kk);
	viewer.ngui->addVariable<bool>("boolvariable", [&](bool var) {boolvariable = var; viewer.core.is_animating = true; },
		[&]() {return boolvariable; });
	viewer.ngui->addButton("drawedge", [&]() {viewer.data.clear(); initedge(); findsaddle(boolvariable, vh[kk]); drawedge(); });

	viewer.screen->performLayout();
	return false;
	};*/
	viewer.launch();
	/*PMyMesh::VertexIHalfedgeIter vheter = mesh.vih_begin(v);
	v1 = mesh.from_vertex_handle(*vheter);*/

	/*printf_s("%d \r\n", v.idx());
	for (list<int>::iterator lter=mylist.begin();lter!=mylist.end();lter++)
	{
		printf_s("Ò»´Î\r\n");
	}
	if (mylist.empty())
	{
		printf_s("shi");
	}
	printf_s("%d \r\n", mesh.n_vertices());*/
	/*int n;
	scanf_s("%d",&n);*/
	return 0;

}