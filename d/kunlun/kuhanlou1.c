inherit ROOM;

void create()
{
        set("short", "�ຮ¥һ��");
        set("long", @LONG
�����ǿຮ¥�ĵײ㡣�ຮ¥�ṹ�򵥣�����ΪŨ�ܵ���
ɼ��Χ��ȡ���ԡ�÷�����Կຮ����֮�⣬����������ǰ��Ϊ
�˼�����������ɵ��Ӷ����ģ����Ͽ���������ľ¥�����ƶ�
�ϣ��ƺ����޾�ͷ����ש���൱�ྻ�������������˴�ɨ��
LONG);
        set("exits", ([
                "up" : __DIR__"kuhanlou2",
                "out" : __DIR__"shanlin1",
        ]));

        setup();
        replace_program(ROOM);
}
