inherit ROOM;

void create()
{
	set("short", "���ź�Ժ");
	set("long", @LONG
���������ŵĺ�Ժ����ɨ�÷ǳ��ɾ��������ǹ��˵�Χǽ��
LONG);
	set("exits", ([  
                "north" : __DIR__"ymzhengting",
        ]));
	
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
