inherit ROOM;

void create()
{
        set("short", "�����");
        set("long", @LONG
�����ǽ𶥻����ֶ����ǽӴ���ͼ������ĵط�����
�ڰ��ż������ӣ�����Χ���������ӡ�ǽ�����ż����ֻ���ǽ
��һ����ܣ����ϰ������顣�м�λ���������Ʒ��������
��ǽ�ϵ��ֻ����ļ��ϵľ��顣����������ʮ����Ĺ�����
��һλʦ̫�����йس��ҵ��¡�һ��ʮ�����Сʦ̫����æǰ
æ���д����ˡ�
LONG);
        set("objects", ([
                CLASS_D("emei") + "/he" : 1,
                CLASS_D("emei") + "/wenhui" : 1,
        ]));
        set("exits", ([
                "west" : __DIR__"hcazhengdian", 
        ]));
        setup();
        replace_program(ROOM);
}