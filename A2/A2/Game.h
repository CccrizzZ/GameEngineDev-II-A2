#pragma once
#include "World.h"





class A1 : public D3DApp
{
public:
	A1(HINSTANCE hInstance);
	A1(const A1& rhs) = delete;
	A1& operator=(const A1& rhs) = delete;
	~A1();

	virtual bool Initialize()override;





	
    // getters for resources map ref
	std::vector<std::unique_ptr<RenderItem>>& getRenderItems() { return mAllRitems; }
	std::unordered_map<std::string, std::unique_ptr<Material>>& getMaterials() { return mMaterials; }
	std::unordered_map<std::string, std::unique_ptr<MeshGeometry>>& getGeometries() { return mGeometries; }
	std::unordered_map<std::string, std::unique_ptr<Texture>>& getTextures() { return mTextures; }


private:
	virtual void OnResize()override;
	virtual void Update(const GameTimer& gt)override;
	virtual void Draw(const GameTimer& gt)override;

	virtual void OnMouseDown(WPARAM btnState, int x, int y)override;
	virtual void OnMouseUp(WPARAM btnState, int x, int y)override;
	virtual void OnMouseMove(WPARAM btnState, int x, int y)override;

	void OnKeyboardInput(const GameTimer& gt);
	void UpdateCamera(const GameTimer& gt);
	void UpdateObjectCBs(const GameTimer& gt);
	void UpdateMaterialCBs(const GameTimer& gt);
	void UpdateMainPassCB(const GameTimer& gt);

	void LoadTextures();
	void BuildRootSignature();
	void BuildDescriptorHeaps();
	void BuildShadersAndInputLayout();

	void helpBuildSubMesh(GeometryGenerator::MeshData name,
		SubmeshGeometry& subName,
		UINT nameVertexOffset,
		UINT nameIndexOffset);

	void BuildShapeGeometry();
	void BuildShapeRenderItems();
	void BuildPSOs();
	void BuildFrameResources();
	void BuildMaterials();
	void DrawRenderItems(ID3D12GraphicsCommandList* cmdList, const std::vector<RenderItem*>& ritems);

	std::array<const CD3DX12_STATIC_SAMPLER_DESC, 6> GetStaticSamplers();





	// Entity
	std::unique_ptr<RenderItem> Plane;
	std::unique_ptr<RenderItem> Background;





private:

	std::vector<std::unique_ptr<FrameResource>> mFrameResources;
	FrameResource* mCurrFrameResource = nullptr;
	int mCurrFrameResourceIndex = 0;

	UINT mCbvSrvDescriptorSize = 0;

	ComPtr<ID3D12RootSignature> mRootSignature = nullptr;

	ComPtr<ID3D12DescriptorHeap> mSrvDescriptorHeap = nullptr;

	// map for geometry
	std::unordered_map<std::string, std::unique_ptr<MeshGeometry>> mGeometries;

	// // map for material
	std::unordered_map<std::string, std::unique_ptr<Material>> mMaterials;

	// map for texture
	std::unordered_map<std::string, std::unique_ptr<Texture>> mTextures;

	// map for shaders
	std::unordered_map<std::string, ComPtr<ID3DBlob>> mShaders;

	// map for pipeline stage
	std::unordered_map<std::string, ComPtr<ID3D12PipelineState>> mPSOs;

	std::vector<D3D12_INPUT_ELEMENT_DESC> mInputLayout;

	// List of all the render items.
	std::vector<std::unique_ptr<RenderItem>> mAllRitems;

	// Render items divided by PSO.
	std::vector<RenderItem*> mRitemLayer[(int)RenderLayer::Count];

	PassConstants mMainPassCB;

	XMFLOAT3 mEyePos = { 0.0f, 0.0f, 0.0f };
	XMFLOAT4X4 mView = MathHelper::Identity4x4();
	XMFLOAT4X4 mProj = MathHelper::Identity4x4();

	float mTheta = 1.5f * XM_PI; 
	float mPhi = XM_PIDIV2 - 0.1f;
	float mRadius = 50.0f;

	POINT mLastMousePos;


    World* mWorld= new World();
};