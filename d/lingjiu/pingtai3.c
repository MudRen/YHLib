inherit ROOM;

void create()
{
  	set("short", "ɽ��ƽ̨");
  	set("long", @LONG
����ʧ��������һ���ƽ̨��ƽ̨��Χ�������ˡ����
ͨ�����չ��ıؾ�֮·��ɽ����һ��ӥ�ͻ���ľ��ҽضϣ���
�ҹ�ɼ��ˣ�ֻ���м�һ��խխ��ʯ��ͨ��ɽ������һͷ����
���Զ�����ż��Ե��ݣ��м���������ʿ���������������
˯���㿴��Ҳ�������߹�ȥ��Ϣһ�����
LONG);
        set("sleep_room", 1);
        set("no_fight", 1);
        set("outdoors", "lingjiu");
        set("exits",([
                "north" : __DIR__"shandao",
        ]));

        setup();
        replace_program(ROOM);
}
