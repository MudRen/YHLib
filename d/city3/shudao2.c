inherit ROOM;

void create()
{
        set("short", "��ʯ·" );
        set("long", @LONG
һ����ʯ�̳ɵ�·��ƽ̹������·�����档����������
���������˶�������ȥ�˳�����ЪЪ�ţ�һЩС��Ҳ�˻�����
�����ԺȵĶ��������������Ͽ�ȥ����Լ���Կ������ڵĳ�
����
LONG);
        set("exits", ([
  		"east" : __DIR__"shudao1",
  		"southwest" : __DIR__"shudao3",
   	]));

        set("no_clean_up", 0);
        set("outdoors", "chengdu");
        set("objects", ([
                "/d/beijing/npc/girl2" : 1,
        ]));
        setup();
        replace_program(ROOM);
}
