inherit ROOM;

void create()
{
        set("short", "�ܵ�");
        set("long", @LONG
�����Ǻ�Ա�������µ��ܵ�����˵���軧���ڽɲ����⣬
����Ա���צ��ץ���������������ܺ�����һЩǳ��ɫ�ɵ�
Ѫ�գ������м�����һ������ë���Ȼ���������㲻�ɵ���Щ
�������������뻹�ǸϿ��뿪����ɡ�
LONG);
        set("exits", ([
                "southeast" : __DIR__"fu-mishi",
        ]));
        setup();
        replace_program(ROOM);
}
