inherit ROOM;

void create()
{
	set("short", "����̨");
	set("long", @LONG
��������̨�ɴ���ʯ������ÿ���ʯ����ü���ƽ������
����Ϊ����������������ģ�������£��ƿ����ʣ����費����
��Ŀ��������ң���ɸ����ţ��ƺ�����һ�ߣ���������������
�����ڣ����϶��ǵ�����ɽ��
LONG );
	set("exits", ([
		"eastdown" : __DIR__"junjigate",
	]));
	set("outdoors", "songshan");
        set("objects", ([
                CLASS_D("songshan") + "/zuo" : 1,
        ]));    
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

