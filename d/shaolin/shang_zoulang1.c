inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����̼ұ��ڵ�һ��ľ�Ƶ����ȣ����������ǹ⻬������
���ȱ�������һ����Ⱦ���㲻ʱ�ܹ����������̼ұ��ļҶ��ڴ�
�߶���æµ����ͣ��
LONG);
	set("exits", ([
		"north"  : __DIR__"shang_zoulang2",
		"south"  : __DIR__"shang_houting",
	]));
        set("objects", ([
                __DIR__"npc/shang1" : 1,
        ]));
	setup();
	replace_program(ROOM);
}
