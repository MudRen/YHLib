inherit ROOM;

void create()
{
  	set("short", "ʧ����");
  	set("long", @LONG
����ͨ�����չ��ıؾ�֮·��ɽ����һ����ӥ�ͻ���ľ�
�ҽضϣ����ҹ�ɼ��ˣ�ֻ���м������һ��խխ��ʯ��ͨ��
ɽ������һͷ����С�����������̤����ȥ��ʧ���ҵ��Ҳ���
һ���ƽ̨����ϡ��ȥ�����в�����������ۻᡣ
LONG );
        set("outdoors", "lingjiu");
        set("exits",([
                "northup"  : __DIR__"jian",
                "eastdown" : __DIR__"ya",
                "east" : __DIR__"shandao",
        ]));
        set("objects",([
                CLASS_D("lingjiu") + "/zhuo" : 1,
                "/clone/npc/walker" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
