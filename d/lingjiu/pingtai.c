inherit ROOM;

void create()
{
  	set("short", "ɽ��ƽ̨");
  	set("long", @LONG
����ʧ��������һ���ƽ̨��ƽ̨��Χ�������ˡ����
ͨ�����չ��ıؾ�֮·��ɽ����һ��ӥ�ͻ���ľ��ҽضϣ���
�ҹ�ɼ��ˣ�ֻ���м�һ��խխ��ʯ��ͨ��ɽ������һͷ��
LONG);
        set("outdoors", "lingjiu");
        set("exits",([
                "west" : __DIR__"shandao",
        ]));
        set("objects",([
                CLASS_D("lingjiu") + "/li" : 1,
                CLASS_D("lingjiu") + "/sang" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
