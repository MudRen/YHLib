inherit ROOM;

void create()
{
  	set("short", "ƽ̨ɽ��");
  	set("long", @LONG
ɽ����һ����ӥ�ͻ���ľ��ҽضϣ����ҹ�ɼ��ˣ�ֻ��
�м������һ��խխ��ʯ��ͨ��ɽ������һͷ����С�������
����̤����ȥ���Ҳ���һ���ƽ̨����ϡ��ȥ�����в�������
����ۻᡣ
LONG);
        set("outdoors", "lingjiu");
        set("exits", ([
                "south" : __DIR__"shandao",
        ]));
        set("objects",([
                CLASS_D("lingjiu") + "/zuo" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
