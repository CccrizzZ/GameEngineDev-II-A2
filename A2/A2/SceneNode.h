#pragma once
#include "../../Common/d3dApp.h"
#include "../../Common/MathHelper.h"
#include "../../Common/UploadBuffer.h"
#include "../../Common/GeometryGenerator.h"
#include "../../Common/Camera.h"
#include "../../Common/FrameResource.h"


using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;
using namespace std;

#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")





// class A1;



// struct RenderItem
// {
//     RenderItem() = default;

// 	XMFLOAT4X4 World = MathHelper::Identity4x4();
// 	XMFLOAT4X4 TexTransform = MathHelper::Identity4x4();
// 	int NumFramesDirty = gNumFrameResources;
// 	UINT ObjCBIndex = -1;
// 	Material* Mat = nullptr;
// 	MeshGeometry* Geo = nullptr;
// 	D3D12_PRIMITIVE_TOPOLOGY PrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
// 	UINT IndexCount = 0;
// 	UINT StartIndexLocation = 0;
// 	int BaseVertexLocation = 0;
// };

class RenderItem
{
public:
	RenderItem() = default;
	XMFLOAT4X4 World = MathHelper::Identity4x4();
	XMFLOAT4X4 TexTransform = MathHelper::Identity4x4();
	int NumFramesDirty = gNumFrameResources;
	UINT ObjCBIndex = -1;
	Material* Mat = nullptr;
	MeshGeometry* Geo = nullptr;
	D3D12_PRIMITIVE_TOPOLOGY PrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	UINT IndexCount = 0;
	UINT StartIndexLocation = 0;
	int BaseVertexLocation = 0;
};


class SceneNode
{
public:
	SceneNode();
	// SceneNode(A1* gRef);
    ~SceneNode();

	// typedef std::unique_ptr<SceneNode> sNode_Ptr;
	
	// setters
	void setPosition(float x, float y, float z);
	void setRotation(float x, float y, float z);
	void setScale(float x, float y, float z);


	// getters
	XMFLOAT3 getPosition();
	XMFLOAT3 getRotation();
	XMFLOAT3 getscale();
	XMFLOAT4X4 getTransform();


	// attach and detach child node from this node
	// void AttachChildNode(sNode_Ptr child);
	// sNode_Ptr DetachChildNode(SceneNode& child);


	// // node initialization
	// void Init();
	// void InitChildrenNode();
	// virtual void InitCurrentNode();


	// // node update
	// void Update(const GameTimer& gt);
	// void UpdateChildrenNode(const GameTimer& gt);
	// virtual void UpdateCurrentNode(const GameTimer& gt);


	// // node draw
	// void Draw();
	// void DrawChildrenNode();
	// virtual void DrawCurrentNode();







	// move node to position
	void MoveTo(float x, float y, float z);

	// game reference
	// A1* GameRef;


	// // scene node parent pointer
	// SceneNode* ParentNode;

	// // scene node children
	// vector<sNode_Ptr> ChildrenList;

	// transform
	XMFLOAT3 Position;
	XMFLOAT3 Rotation;
	XMFLOAT3 Scale;



};

