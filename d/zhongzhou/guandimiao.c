inherit ROOM;

void create()
{
	set("short", "����");
        set("long", @LONG
����С���е�һ�����������Ƶ���שɢ���ڵ��£���
ǽ����¶����һ���������ѿ�������������ɫ�������л�����
ɢ�������ſڡ�
LONG);

        set("exits", ([  
                "southeast" : __DIR__"xiaoxiang1",          
		"enter":__DIR__"inpomiao",
        ]));
        set("objects",([
                "/d/kaifeng/npc/qigai" : 2,
        ]));

        setup();
        replace_program(ROOM);
}
