inherit ROOM;

void create()
{
	set("short","������");
	set("long",@LONG
�����ǳɶ������⸮���š��ɶ��Թž��Ǵ����׸�������
���ϺӼгǶ�������Ϊ��Ȼ�Ļ��Ǻӡ������Ĵ�����Ͽ������
��֮�գ�����������֮�̣��ɶ�ȴ��֮���������سɹ�֮����
�����������£�����߳��ˡ�
LONG);
	set("outdoors", "chengdu");
	set("exits", ([
            	"east"  : __DIR__"road2",
            	"west"  : __DIR__"eastgate",
	]));
        set("objects", ([
                "/clone/npc/walker" : 1,
        ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

