inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
��������������ľ�Ծ����ϣ����Ǹ����������������
���̡��乹���������¥�����濪�ţ����ݿ����£��ϸ��糵
��״���в�ס�ˣ��������²㣬һ��Ϊţ��Ȧ��
LONG);
        set("objects",([
                "/clone/quarry/yang2" : 2,
        ]));
        set("outdoors", "dali");
        set("exits", ([
                "north"   : __DIR__"nongtian2",
                "up"      : __DIR__"langan2",
        ]));
        setup();
        replace_program(ROOM);
}
