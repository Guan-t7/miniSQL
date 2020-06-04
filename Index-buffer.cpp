
void IndexManager::loadIndexInfos()
{
	catalogManage cm;
	fileNode *ftmp = bm.getFile("Indexes");
	blockNode *btmp = bm.getBlockHead(ftmp);
	while (btmp ) 
	{
		char* addressBegin;
		addressBegin = bm.get_content(*btmp);
		if (addressBegin - bm.get_content(*btmp)< bm.get_usingSize(*btmp)) {
			string s = addressBegin;
			addressBegin += size(s);
			if (s.empty()) break;
			while (!s.empty())
			{
				IndexInfo* i = new IndexInfo;
				*i = cm.readBufferIndexes(s);
				api api;
				api.createIndex(i->indexName, i->tableName, i->Attribute);
				delete i;
			}
		}
		if (btmp->nextBlock == NULL)
		{
			break;
		}
		else 
		{
			btmp = btmp->nextBlock;
		}
	}
	return ;
}

int IndexManager::writeIndexInfosintoBuffer() {
	map<int, IndexInfo*>::iterator it;
	catalogManage cm;
	fileNode *ftmp = bm.getFile("Indexes");
	blockNode *btmp = bm.getBlockHead(ftmp);
	bm.set_usingSize(*btmp, 0);
	memset(bm.get_content(*btmp), 0, bm.getBlockSize());
	for (it = indexMap.begin(); it != indexMap.end(); it++)
	{
		string s;
		s = cm.writeBuffer(*it->second);
		while (true) 
		{
			if (bm.get_usingSize(*btmp) <= bm.getBlockSize() - size(s)) {

				char *addressBegin;
				addressBegin = bm.get_content(*btmp) + bm.get_usingSize(*btmp);
				memcpy(addressBegin, s.c_str(), size(s));
				bm.set_usingSize(*btmp, bm.get_usingSize(*btmp) + size(s));
				bm.set_dirty(*btmp);
				break;
			}
			else if (btmp->nextBlock == NULL) 
			{
				btmp = bm.getNextBlock(ftmp, btmp);
			}
			else 
			{
				btmp = btmp->nextBlock;
			}
		}		
	}
	return 0;
}