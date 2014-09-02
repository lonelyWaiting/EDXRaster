#include "Mesh.h"
#include "InputBuffer.h"
#include "Graphics/ObjMesh.h"
#include "Memory/Memory.h"


namespace EDX
{
	namespace RasterRenderer
	{
		void Mesh::LoadMesh(const Vector3& pos,
			const Vector3& scl,
			const Vector3& rot,
			const char* path)
		{
			ObjMesh mesh;
			mesh.LoadFromObj(pos, scl, rot, path);

			mpVertexBuf = CreateVertexBuffer(&mesh.GetVertexAt(0), mesh.GetVertexCount());
			mpIndexBuf = CreateIndexBuffer(mesh.GetIndexAt(0), mesh.GetTriangleCount());
		}

		void Mesh::LoadPlane(const Vector3& pos,
			const Vector3& scl,
			const Vector3& rot,
			const float length)
		{
			ObjMesh mesh;
			mesh.LoadPlane(pos, scl, rot, length);

			mpVertexBuf = CreateVertexBuffer(&mesh.GetVertexAt(0), mesh.GetVertexCount());
			mpIndexBuf = CreateIndexBuffer(mesh.GetIndexAt(0), mesh.GetTriangleCount());
		}

		void Mesh::LoadSphere(const Vector3& pos,
			const Vector3& scl,
			const Vector3& rot,
			const float radius,
			const int slices,
			const int stacks)
		{
			ObjMesh mesh;
			mesh.LoadSphere(pos, scl, rot, radius, slices, stacks);

			mpVertexBuf = CreateVertexBuffer(&mesh.GetVertexAt(0), mesh.GetVertexCount());
			mpIndexBuf = CreateIndexBuffer(mesh.GetIndexAt(0), mesh.GetTriangleCount());
		}
	}
}