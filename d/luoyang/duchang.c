inherit ROOM;

void create()
{
	set("short", "���ַ�");
	set("long", @LONG
�ڴ����Ϲ���һ���ɫ�����ӣ����������˸����ġ��ġ��֣�ԭ��
������һ���ĳ����Ϳ���·�ߣ�����ҡѽ���߽��ĳ���ȴ��������Ĳ���
��˷��������֡���Ǯ�û�֮�������ڶ���Ѻעʱ�ĵ�ߺ���������ÿ��
�˵Ķ��䣬����Ի��ʮ�ľ��䡰��һ��̤����������Ի�ͷ�ˣ��������
�ҵ�����������ɢ���ǲ�֪����ڵģ�ֻ����������Ӯ�Ҳ��Ƕ�ͽ����Ľ
�Ķ�������ĵ�ϣ����
LONG);
	set("no_clean_up", 0);
	set("exits", ([
  		"east" : __DIR__"sroad3",
	]));
        set("objects", ([
                "/d/kaifeng/npc/guanbing" : 1,
                "/d/city/npc/liumang" : 2,
                "/d/beijing/npc/haoke1" : 2,
                "/d/beijing/npc/duke" : 3,
        ]));
	setup();
	replace_program(ROOM);
}
