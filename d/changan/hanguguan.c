inherit  ROOM;

void  create  ()
{
	set("short",  "���ȹ�");
	set("long",  @LONG
������ǹź��Źء���������ɽ���������򣬹�����С�����ǿ��һ
��֮�أ��ƹض������������Զ�������ɨ���£�������Ϊ���ݴˣ�����
�����˿��أ���������ʤ֮������������������Ҳ���ڴ�����������¾���
ǧ�����£��������ж�������
LONG);
	set("exits",  ([
		"southeast"  :  __DIR__"road1",
		"west"  :  "/d/luoyang/guandaoe4",
	]));
	set("outdoors", "luoyang");
        set("objects", ([
                 __DIR__"npc/tianlong" : 1,
        ]));

	setup();
	replace_program(ROOM);
}
